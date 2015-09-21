/*
 * 06. String Selection Sort
 *
 * Uses the selection sort algorithm to sort an array of strings.
 */
 
#include <iostream>
#include <string>

using namespace std;

const int NUM_NAMES = 20;
string names[NUM_NAMES] =
{
	"Collins, Bill", "Smith, Bart", "Allen, Jim",
	"Griffin, Jim", "Stamey, Marty", "Rose, Geri",
	"Taylor, Terri", "Johnson, Jill",
	"Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
	"James, Jean", "Weaver, Jim", "Pore, Bob",
	"Rutherford, Greg", "Javens, Renee",
	"Harrison, Rose", "Setzer, Cathy",
	"Pike, Gordon", "Holland, Beth"
};

void sort(string [], const int);

int main()
{
	sort(names, NUM_NAMES);
	for (int i = 0; i < NUM_NAMES; i++)
	{
		cout << names[i] << endl;
	}
	return 0;
}


void sort(string names[], const int length)
{
	string smallest;
	int smallestIndex;
	int start = 0;
	
	do
	{
		smallest = names[start];
		smallestIndex = start;
	
		for (int i = start; i < length; i++)
		{
			if (names[i] < smallest)
			{
				smallest = names[i];
				smallestIndex = i;
			}
		}
		names[smallestIndex] = names[start];
		names[start++] = smallest;
	} while (start < length);
}

