/*
 * 19.02 Recursive Conversion
 *
 * Convert an iterative function to a recursive one.
 */

#include <iostream>

using namespace std;

/*
 * This function operates the same as written in the book, except this
 * version blows the stack and will not run infinitely.  The book probably
 * didn't intend on an infinite loop, but that's what is written.
 */
void sign(int n)
{
	cout << "No Parking\n";
	sign(n);
}

int main()
{
	sign(4);
	return 0;
}
