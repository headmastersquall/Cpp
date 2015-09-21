/*
 * 10. Sorting Orders
 *
 * Shows the steps of a bubble sort and a selection sort on two
 * identical arrays.
 */
 
#include <iostream>

using namespace std;

const int ARRAY_LENGTH = 8;

void bubbleSort(int [], const int);
void selectionSort(int [], const int);
void showArray(int [], const int);

int main()
{
	int array1[] = { 4, 23, 55, 5, 10, 44, 2, 7 };
	int array2[ARRAY_LENGTH];
	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		array2[i] = array1[i];
	}

	cout << "Sorting via bubble sort" << endl;
	showArray(array1, ARRAY_LENGTH);
	bubbleSort(array1, ARRAY_LENGTH);
	
	cout << "Sorting via selection sort" << endl;
	showArray(array2, ARRAY_LENGTH);
	selectionSort(array2, ARRAY_LENGTH);
	return 0;
}

void bubbleSort(int nums[], const int length)
{
	bool hasChanges;
	int tmp;
	
	do
	{
		hasChanges = false;
		for (int i = 0; i < length - 1; i++)
		{
			if (nums[i + 1] < nums[i])
			{
				tmp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = tmp;
				hasChanges = true;
			}
		}
		showArray(nums, length);
	} while (hasChanges);
}

void selectionSort(int nums[], const int length)
{
	int smallest;
	int smallestIndex;
	int start = 0;
	
	do
	{
		smallest = nums[start];
		smallestIndex = start;
	
		for (int i = start; i < length; i++)
		{
			if (nums[i] < smallest)
			{
				smallest = nums[i];
				smallestIndex = i;
			}
		}
		nums[smallestIndex] = nums[start];
		nums[start++] = smallest;
		showArray(nums, length);
	} while (start < length - 1);
}

void showArray(int nums[], const int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}

