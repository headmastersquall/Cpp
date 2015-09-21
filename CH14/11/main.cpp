/*
 * 14.11 FeetInches Class Copy Constructor and multiply function.
 *
 * Adds a copy constructor and a multiply to the FeetInches class.
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

	// To demonstrate the copy constructor
	FeetInches fi3(fi2);

	cout << "Multiplying first measurement with the second" << endl;
	result = fi1.multiply(fi3);
	showFeetInches(result);

	return 0;
}
