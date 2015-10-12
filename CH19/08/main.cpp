/*
 * 19.06 Recursive Power Function
 *
 * Calculate the power of a number using recursion.
 */

#include <iostream>
#include <string>

using namespace std;

bool isMember(int nums[], int size, int number, int startIndex = 0)
{
	if (startIndex == size)
		return false;
	else if (nums[startIndex] == number)
		return true;
	else
		return isMember(nums, size, number, startIndex + 1);
}

string toYesNo(bool b)
{
	return b ? "Yes" : "No";
}

int main()
{
	const int NUMS_SIZE = 5;
	int nums[] { 4, 9, 10, 44, 5 };
	cout << "Has number 9: " << toYesNo(isMember(nums, NUMS_SIZE, 9)) << endl;
	cout << "Has number 15: " << toYesNo(isMember(nums, NUMS_SIZE, 15)) << endl;
	return 0;
}
