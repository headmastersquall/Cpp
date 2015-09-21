/*
 * 1. Sum of Numbers
 */

#include <iostream>

using namespace std;

int main()
{
	int end,
		total = 0;
	cout << "Enter an ending number: ";
	cin >> end;

	if (end < 0)
	{
		cout << "The ending number must not be negative" << endl;
		return 1;
	}

	for (int i = 1; i != end + 1; i++)
	{
		total += i;
	}
	cout << "The sum of the numbers 1 to " << end << " is " << total << endl;

	return 0;
}

