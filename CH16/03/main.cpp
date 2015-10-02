/*
 * 15.13 Pure Abstract Base Class Project
 *
 * Define a pure abstract base class called BasicShape.  Several shapes
 * provided that inherit from this base class.
 */

#include <iostream>

using namespace std;

template <class T>
T minimum(T a, T b)
{
	return a < b ? a : b;
}

template <class T>
T maximum(T a, T b)
{
	return a > b ? a : b;
}

int main()
{
	int a = 4;
	int b = 9;
	double c = 4.56;
	double d = 1.33;

	cout << "The largest int is " << maximum(a, b) << endl;
	cout << "The smallest int is " << minimum(a, b) << endl;
	cout << endl;

	cout << "The largest double is " << maximum(c, d) << endl;
	cout << "The smallest double is " << minimum(c, d) << endl;
	cout << endl;
	return 0;
}
