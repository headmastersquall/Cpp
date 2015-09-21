/*
 * 01. Array Allocator
 *
 * Creates a function to dynamically allocate an array.
 */
 
#include <iostream>
#include <memory>

using namespace std;

unique_ptr<int[]> createArray(int);

int main() {
	const int SIZE = 4;
	unique_ptr<int[]> arr = createArray(SIZE);
	
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = i;
	}
	
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

unique_ptr<int[]> createArray(const int size) {
	unique_ptr<int[]> arr(new int[size]);
	return arr;
}

