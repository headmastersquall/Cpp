/*
 * 19.04 Recursive Array Sum
 *
 * Provides a function that accepts an int array and calculates a sum
 * using recursions.
 */

#include <iostream>

using namespace std;

int sum(int nums[], int size, int base, int index)
{
	if (index == size)
		return base;
	else
		return sum(nums, size, base + nums[index], index + 1);
}

int main()
{
	int NUMBERS_SIZE = 10;
	int numbers[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "The sum is " << sum(numbers, NUMBERS_SIZE, 0, 0) << endl;;
	return 0;
}
