/*
 * 19.05 Recursive Multiplication
 */

#include <iostream>

using namespace std;

int _recMult(int x, int y, int product)
{
	if (x == 0)
	{
		return product;
	}
	else
	{
		return _recMult(x -= 1, y, product + y);
	}
}

int multiply(int x, int y)
{
	return _recMult(x, y, 0);
}

int main()
{
	cout << "8 * 14 = " << multiply(8, 14) << endl;
	return 0;
}
