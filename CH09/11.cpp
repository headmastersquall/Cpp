/*
 * 11. Array Expander
 *
 * Provides a function that accepts an array and returns a pointer
 * to a new array that is double the size as the provided array.
 * New elements are initialized to zero.
 */

#include <iostream>

using namespace std;

int *expand(int const *, const int);
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
	int *expanded = expand(array, SIZE);
	showArray(expanded, SIZE * 2);
	
	delete [] expanded;
	expanded = nullptr;
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

int *expand(int const *arr, const int size)
{
	int expandedSize = size * 2;
	int *expanded = nullptr;
	expanded = new int[expandedSize];
	
	for (int i = 0; i < size; i++)
	{
		expanded[i] = arr[i];
	}
	for (int i = size; i < expandedSize; i++)
	{
		expanded[i] = 0;
	}
	return expanded;
}

