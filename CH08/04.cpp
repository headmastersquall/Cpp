/*
 * 04. Charge Account Validation Modification
 *
 * Validates a charge account number provided by the user.
 * Uses a selection sort algorithm to sort the array, then searches
 * it using a binary search.
 */
 
#include <iostream>

using namespace std;

const int NUMBER_COUNT = 18;
const int NOT_FOUND = -1;

int accountNumbers[]
{
	5658845, 8080152, 1005231, 4520125, 4562555,
	6545231, 7895122, 5552012, 3852085, 8777541,
	5050552, 7576651, 8451277, 7825877, 7881200,
	1302850, 1250255, 4581002
};

void sort(int [], const int);
bool accountNumberValid(const int);
int binarySearch(const int [], const int, const int);

int main ()
{
	int accountNumber;
	cout << "Enter your charge account number: ";
	cin >> accountNumber;
	
	sort(accountNumbers, NUMBER_COUNT);
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

void sort(int numbers[], const int length)
{
	int smallest;
	int smallestIndex;
	int start = 0;
	
	do
	{
		smallest = numbers[start];
		smallestIndex = start;
	
		for (int i = start; i < length; i++)
		{
			if (numbers[i] < smallest)
			{
				smallest = numbers[i];
				smallestIndex = i;
			}
		}
		numbers[smallestIndex] = numbers[start];
		numbers[start++] = smallest;
	} while (start < length);
}

bool accountNumberValid(const int accountNumber)
{
	return binarySearch(
		accountNumbers,
		NUMBER_COUNT,
		accountNumber) != NOT_FOUND;
}

int binarySearch(const int numbers[], const int length, const int value)
{
	int first = 0;
	int last = length - 1;
	int middle;
	
	while (first <= last)
	{
		middle = (first + last) / 2;
		if (numbers[middle] == value)
		{
			return middle;
		}
		else if (numbers[middle] > value)
		{
			last = middle -1;
		}
		else
		{
			first = middle + 1;
		}
	}	
	return NOT_FOUND;
}

