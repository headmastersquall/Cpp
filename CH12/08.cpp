/*
 * 12.08 Array/File Functions
 *
 * Write an array of numbers to a file, then read it back.  Write the
 * contents to the console of what was read back from the file.
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void arrayToFile(const char* fileName, const int* numbers)
{
	fstream file(fileName, ios::out | ios::binary);
	file.write(reinterpret_cast<char*>(&numbers), sizeof(numbers));
	file.close();
}

void fileToArray(const char* fileName, const int* numbers, const int size)
{
	fstream file(fileName, ios::in | ios::binary);
	file.read(reinterpret_cast<char*>(&numbers), size);
	file.close();
}

void showArray(const int* numbers, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << numbers[i] << endl;
	}
}

int main()
{
	const int SIZE = 8;
	const char* fileName = "nums";
	int numbers[SIZE] = { 1, 3, 5, 7, 9, 11, 13, 15 };
	arrayToFile(fileName, numbers);
	fileToArray(fileName, numbers, SIZE);
	showArray(numbers, SIZE);
    return 0;
}

