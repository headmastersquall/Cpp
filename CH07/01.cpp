/*
 * 01. Larges/Smallest Array Values
 *
 * Fill an array with user input, then show the smallest and largest values.
 */

#include <iostream>
#include <string>

using namespace std;

int intPrompt(string prompt);
void findAndShowSmallLarge(int [], int);

int main()
{
	const int NUMBER_COUNT = 10;
	const string PROMPT = "Enter a number: ";
	int numbers[NUMBER_COUNT];

	for (int i = 0; i < NUMBER_COUNT; i++)
	{
		numbers[i] = intPrompt(PROMPT);
	}
	findAndShowSmallLarge(numbers, NUMBER_COUNT);
	return 0;
}

int intPrompt(const string prompt)
{
	int value;
	cout << prompt;
	cin >> value;
	return value;
}

void findAndShowSmallLarge(int nums[], const int size)
{
	int smallest = nums[0];
	int largest = nums[0];

	for (int i = 0; i < size; i++)
	{
		smallest = nums[i] < smallest ? nums[i] : smallest;
		largest = nums[i] > largest ? nums[i] : largest;
	}
	
	cout << "The largest number is: " << largest << endl;
	cout << "The smallest number is: " << smallest << endl;
}

