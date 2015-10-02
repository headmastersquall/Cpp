#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
	string getMonthName();

public:
	Date(int yyyy, int mm, int dd);
	string ToShortString();
	string ToLongString1();
	string ToLongString2();

	class InvalidDay {};
	class InvalidMonth {};
};

#endif
