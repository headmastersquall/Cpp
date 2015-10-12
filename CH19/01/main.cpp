/*
 * 19.01 Iterative Factorial
 *
 * Iterative version of the factorial function presented in the chapter.
 */

#include <iostream>

using namespace std;

int factorial(const int n)
{
	int f = n;
	for (int i = n - 1; i > 0; i--)
	{
		f *= i;
	}
	return f;
}

int main()
{
	cout << "The factorial of 4 is " << factorial(4);
	return 0;
}
