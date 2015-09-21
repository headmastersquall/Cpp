/*
 * 01. Charge Account Validation
 *
 * Validates a charge account number provided by the user.
 */
 
#include <iostream>

using namespace std;

const int NUMBER_COUNT = 18;

int accountNumbers[]
{
	5658845, 8080152, 1005231, 4520125, 4562555,
	6545231, 7895122, 5552012, 3852085, 8777541,
	5050552, 7576651, 8451277, 7825877, 7881200,
	1302850, 1250255, 4581002
};

bool accountNumberValid(const int);
bool contains(const int [], const int, const int);

int main ()
{
	int accountNumber;
	cout << "Enter your charge account number: ";
	cin >> accountNumber;
	if (accountNumberValid(accountNumber))
	{
		cout << "Your account number is valid." << endl;
	}
	else
	{
		cout << "Invalid account number entered." << endl;
		return 1;
	}
	return 0;
}

bool accountNumberValid(const int accountNumber)
{
	return contains(accountNumbers, NUMBER_COUNT, accountNumber);
}

bool contains(const int a[], const int size, const int value)
{
	for (int i = 0; i < size; i++)
	{
		if (value == a[i])
		{
			return true;
		}
	}
	return false;
}

