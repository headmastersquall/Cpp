#include "Date.h"
#include <string>
#include <cstdlib>

using namespace std;

int getDaysInMonth(int month, int year)
{
	int daysInMonth[] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return month == 2 && year % 4 == 0
		? daysInMonth[month - 1] + 1
		: daysInMonth[month -1];
}

Date::Date(int yyyy, int mm, int dd)
{
	year = yyyy;
	month = mm >= 1 && mm <= 12 ? mm : 1;
	day = dd >= 1 && dd <= 31 ? dd : 1;
}

string Date::toShortString() const
{
	return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

string Date::toLongString1() const
{
	return getMonthName() + " " + to_string(day) + ", " + to_string(year);
}

string Date::toLongString2() const
{
	return to_string(day) + " " + getMonthName() + " " + to_string(year);
}

string Date::getMonthName() const
{
	switch (month) {
		case 1:
			return "January";
		case 2:
			return "February";
		case 3:
			return "March";
		case 4:
			return "April";
		case 5:
			return "May";
		case 6:
			return "June";
		case 7:
			return "July";
		case 8:
			return "August";
		case 9:
			return "September";
		case 10:
			return "October";
		case 11:
			return "November";
		case 12:
			return "December";
		default:
			return "";
	}
}

Date Date::operator ++()
{
	incDay();
	return *this;
}

Date Date::operator ++(int)
{
	Date origDate(year, month, day);
	incDay();
	return origDate;
}

Date Date::operator --()
{
	decDay();
	return *this;
}

Date Date::operator --(int)
{
	Date origDate(year, month, day);
	decDay();
	return origDate;
}

int Date::operator -(const Date &date)
{
	return abs(toDays(date) - toDays(*this));
}

istream &operator >> (istream &strm, Date &date)
{
	int y;
	cout << "Enter year: ";
	strm >> y;

	int m = 0;
	while (m < 1 || m > 12)
	{
		cout << "Enter month: ";
		strm >> m;
	}

	int daysInMonth = getDaysInMonth(m, y);
	int d = 0;

	while (d < 1 || d > daysInMonth)
	{
		cout << "Enter day: ";
		strm >> d;
	}

	Date newDate(y, m, d);
	date = newDate;

	return strm;
}

ostream &operator << (ostream &strm, const Date &date)
{
	strm << date.toLongString1();
	return strm;
}

void Date::incDay()
{
	day += 1;
	if (day > getDaysInMonth(month, year))
	{
		day = 1;
		month += 1;
	}
	if (month > 12)
	{
		month = 1;
		year += 1;
	}
}

void Date::decDay()
{
	day -= 1;
	if (day < 1)
	{
		month -= 1;
		if (month < 1)
		{
			month = 12;
			year -= 1;
		}
		day = getDaysInMonth(month, year);
	}
}

int Date::toDays(const Date &date)
{
	int m = date.getMonth();
	int d = date.getDay();
	int y = date.getYear();

	// This was found here
	// http://stackoverflow.com/questions/14218894/number-of-days-between-two-dates-c
	if (m < 3)
	{
		y--, m += 12;
	}
	return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}
