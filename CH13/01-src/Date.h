#ifndef DATE_H
#define DATE_H

#include <string>

class Date
{
private:
	int year;
	int month;
	int day;
	std::string getMonthName();

public:
	Date(int yyyy, int mm, int dd);
	std::string ToShortString();
	std::string ToLongString1();
	std::string ToLongString2();
};

#endif
