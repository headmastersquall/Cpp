/*
 * Celsius to Fahrenheit
 *
 * This program prompts the user for Celsius degrees and converts
 * the value to Fahrenheit degrees.
 */

#include <iostream>

using namespace std;

int main()
{
	double celsius, fahrenheit;

	cout << "Enter Celsius temperature to convert: ";
	cin >> celsius;
	
	fahrenheit = ((9.0 / 5.0) * celsius) + 32;
	cout << "The temperature in fahrenheit is: "
	     << fahrenheit << endl;
	return 0;
}
