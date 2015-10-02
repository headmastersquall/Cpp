/*
 * 16.15 STL Binary Search
 *
 * Modification of challenge 8.1 to use STL binary search and a vector instead
 * of an array.
 */
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool accountNumberValid(const vector<int> &accountNumbers, const int accountNumber)
{
	return binary_search(accountNumbers.begin(), accountNumbers.end(), accountNumber);
}

int main ()
{
	vector<int> accountNumbers
	{
		5658845, 8080152, 1005231, 4520125, 4562555,
		6545231, 7895122, 5552012, 3852085, 8777541,
		5050552, 7576651, 8451277, 7825877, 7881200,
		1302850, 1250255, 4581002
	};

	sort(accountNumbers.begin(), accountNumbers.end());
	int accountNumber;
	cout << "Enter your charge account number: ";
	cin >> accountNumber;
	if (accountNumberValid(accountNumbers, accountNumber))
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

