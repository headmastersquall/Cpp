#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

using namespace std;

class Date;

ostream &operator << (ostream &, const Date &);
istream &operator >> (istream &, Date &);

class Date
{
private:
	int year;
	int month;
	int day;
	std::string getMonthName() const;
	void incDay();
	void decDay();
	int toDays(const Date &);

public:
	Date(int yyyy = 1, int mm = 1, int dd = 1);
	std::string toShortString() const;
	std::string toLongString1() const;
	std::string toLongString2() const;
	int getMonth() const { return month; };
	int getDay() const { return day; };
	int getYear() const { return year; };
	Date operator++();
	Date operator++(int);
	Date operator--();
	Date operator--(int);
	int operator-(const Date &);

	friend ostream &operator << (ostream &, const Date &);
	friend istream &operator >> (istream &, Date &);
};

#endif
