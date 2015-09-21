/* 
 * 07. Binary String Search 
 * 
 * Modification of the binary search to search strings instead 
 * of integers. 
 */ 
 
#include <iostream> 
#include <string> 

using namespace std; 

const int NUM_NAMES = 20; 
const int NOT_FOUND = -1; 

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
int binarySearch(const string [], const int, const string); 

int main() 
{ 
	sort(names, NUM_NAMES); 
	string name = "Looney, Joe"; 
	cout << "The index of " << name << " is " 
		 << binarySearch(names, NUM_NAMES, name) << "." << endl; 
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

int binarySearch(const string numbers[], const int length, const string value) 
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

