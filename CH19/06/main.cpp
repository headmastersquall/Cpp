/*
 * 19.06 Recursive Power Function
 *
 * Calculate the power of a number using recursion.
 */

#include <iostream>

using namespace std;

int _recPow(int x, int y, int product)
{
	if (y == 0)
	{
		return product;
	}
	else
	{
		return _recPow(x, y -= 1, product * x);
	}
}

int pow(int x, int y)
{
	return _recPow(x, y - 1, x);
}

int main()
{
	cout << "2 ^ 8 = " << pow(2, 8) << endl;
	return 0;
}
