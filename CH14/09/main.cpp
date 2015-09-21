/*
 * 14.09 Feetinches Modification
 *
 * Redo the poorly written FeetInches class that was created within this
 * chapter and add extra overloaded operators.
 */

#include "FeetInches.h"
#include <iostream>

using namespace std;

void showFeetInches(const FeetInches &fi)
{
	cout << "Feet: " << fi.getFeet() << endl;
	cout << "Inches: " << fi.getInches() << endl;
	cout << endl;
}

int main()
{
	int feet, inches;
	FeetInches result(0, 0);

	cout << "Enter feet for the first measurement: ";
	cin >> feet;
	cout << "Enter inches for the first measurement: ";
	cin >> inches;
	FeetInches fi1(feet, inches);

	cout << "Enter feet for the second measurement: ";
	cin >> feet;
	cout << "Enter inches for the second measurement: ";
	cin >> inches;
	FeetInches fi2(feet, inches);

	result = fi1 + fi2;
	cout << "Adding the two together results in:" << endl;
	showFeetInches(result);

	result = result - fi2;
	cout << "Subtracting the second measurement results in:" << endl;
	showFeetInches(result);

	if (fi1 < fi2)
	{
		cout << "The first measurement is less than the second" << endl;
	}
	else if (fi1 > fi2)
	{
		cout << "The first measurement is greater than the second" << endl;
	}
	else if (fi1 == fi2)
	{
		cout << "The two measurements are equal" << endl;
	}

	if (fi1 <= fi2)
	{
		cout << "The first measurement is less than or equal to the second" << endl;
	}
	else if (fi1 >= fi2)
	{
		cout << "The first measurement is greater than or equal to the second" << endl;
	}
	else if (fi1 != fi2)
	{
		cout << "The two measurements are not equal" << endl;
	}
	return 0;
}
