/*
 * 16.01 Date Exceptions
 *
 * Add exception classes to the Date class created in a previous
 * assignment.
 */

#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	try
	{
		int day, month, year = 0;
		cout << "Enter a day: ";
		cin >> day;

		cout << "Enter a month: ";
		cin >> month;

		cout << "Enter a year: ";
		cin >> year;

		Date date(year, month, day);
		cout << "The date entered is " << date.ToLongString1() << endl;
	}
	catch (const Date::InvalidDay &)
	{
		cout << "Invalid day entered." << endl;
	}
	catch (const Date::InvalidMonth &)
	{
		cout << "Invalid month entered." << endl;
	}
	return 0;
}
