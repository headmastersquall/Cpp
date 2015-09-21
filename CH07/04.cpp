/*
 * 04. Larger Than n
 *
 * Show all items in an array that are greater that a given number.
 */

#include <iostream>

using namespace std;

void showLargerThan(int[], int, int);

int main()
{
	const int SIZE = 10;
	int nums[] = { 2, 9, 5, 10, 14, 12, 1, 20, 22, 25 };
	int largest;
	cout << "Show numbers larger than: ";
	cin >> largest;
	showLargerThan(nums, SIZE, largest);
	return 0;
}

void showLargerThan(int nums[], int size, int largerThan)
{
	for (int i = 0; i < size; i++)
	{
		if (nums[i] > largerThan)
		{
			cout << nums[i] << endl;
		}
	}
}

