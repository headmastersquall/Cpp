/*
 * 10. Reverse Array
 *
 * Provides a function that accepts an array and returns a pointer
 * to a new array that has it's contents in reverse order.
 */

#include <iostream>

using namespace std;

int *reverse(int const *, const int);
void showArray(int const *, const int);

int main()
{
	const int SIZE = 10;
	int array[SIZE];
	
	for (int i = 0; i < SIZE; i++)
	{
		array[i] = i;
	}
	
	showArray(array, SIZE);
	int *reversed = reverse(array, SIZE);
	showArray(reversed, SIZE);
	
	delete [] reversed;
	reversed = nullptr;
	return 0;
}

void showArray(int const *arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int *reverse(int const *arr, const int size)
{
	int *reversed = nullptr;
	reversed = new int[size];
	int insertIndex = size - 1;
	
	for (int i = 0; i < size; i++)
	{
		reversed[insertIndex--] = i;
	}
	return reversed;
}

