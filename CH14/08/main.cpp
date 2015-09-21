/*
 * 14.08 - Date Class Modification
 *
 * Add a bunch of overloaded operators to the Date class created on exercise
 * 10.1.
 */

#include "Date.h"
#include <iostream>

using namespace std;

int main()
{
	Date date1;
	Date date2;
	cout << "Input the first date " << endl;;
	cin >> date1;

	cout << "Input the second date " << endl;;
	cin >> date2;

	cout << date1 - date2 << " days difference between "
		 << date1 << " and " << date2 << endl;

	cout << "Date1 = " << date1 << endl;
	cout << "Adding a day" << endl;
	date1++;
	cout << date1 << endl;
	cout << "Subtracting a day" << endl;
	date1--;
	cout << date1 << endl;

	return 0;
}
