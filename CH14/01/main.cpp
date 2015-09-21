/*
 * 14.01 - Numbers Class
 *
 * Provides a class called Numbers that receives an integer and outputs its
 * worded version.
 */

#include "Numbers.h"
#include <iostream>

using namespace std;

int main()
{
	Numbers n(5874);
	cout << n.ToString() << endl;
	return 0;
}
