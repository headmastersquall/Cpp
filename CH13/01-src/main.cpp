/*
 * 13.01 Date
 *
 * Creates a custom date class that formats the date three different ways.
 */

#include "Date.h"
#include <iostream>

using namespace std;

int main()
{
	Date d(1997, 8, 29);
	cout << d.ToShortString() << endl;
	cout << d.ToLongString1() << endl;
	cout << d.ToLongString2() << endl;
	return 0;
}
