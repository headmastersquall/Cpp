#include "Date.h"
#include <string>

using namespace std;

Date::Date(int yyyy, int mm, int dd)
{
	year = yyyy;
	month = mm >= 1 && mm <= 12 ? mm : 1;
	day = dd >= 1 && dd <= 31 ? dd : 1;
}

string Date::ToShortString()
{
	return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

string Date::ToLongString1()
{
	return getMonthName() + " " + to_string(day) + ", " + to_string(year);
}

string Date::ToLongString2()
{
	return to_string(day) + " " + getMonthName() + " " + to_string(year);
}

string Date::getMonthName()
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
