/*
 * 14.04 - NumDays Class
 *
 * Provides a class called NumDays that is used to convert work hours to
 * work days.
 */

#include "NumDays.h"
#include <iostream>

using namespace std;

int main()
{
	NumDays workHours(9);
	cout << "Work days: " << workHours.getWorkDays() << endl;
	cout << endl;
	cout << "Adding one hour (postfix) " << endl;
	cout << workHours++.getWorkDays() << endl;
	cout << "Work days: " << workHours.getWorkDays() << endl;
	cout << endl;
	cout << "Adding one hour (prefix) " << endl;
	cout << workHours.operator ++().getWorkDays() << endl;
	cout << "Work days: " << workHours.getWorkDays() << endl;
	cout << endl;
	cout << "Subtracting one hour (postfix) " << endl;
	cout << workHours--.getWorkDays() << endl;
	cout << "Work days: " << workHours.getWorkDays() << endl;
	cout << endl;
	cout << "Subtracting one hour (prefix) " << endl;
	cout << workHours.operator --().getWorkDays() << endl;
	cout << "Work days: " << workHours.getWorkDays() << endl;
	cout << endl;
	cout << "Adding ten hours" << endl;
	cout << "Work days: " << (workHours + 10).getWorkDays() << endl;
	cout << endl;
	cout << "Subtracting six hours" << endl;
	cout << "Work days: " << (workHours - 6).getWorkDays() << endl;
	cout << endl;
	return 0;
}
