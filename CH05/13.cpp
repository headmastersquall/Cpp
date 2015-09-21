/*
 * 13. Celsius to Fahrenheit Table
 *
 * This program outputs a table showing the conversion values
 * of Celsius degress to Fahrenheit degrees from the values
 * of 0 through 20.
 */

#include <iostream>

using namespace std;

int main()
{
	double fahrenheit;
	const double CONVERSION = 9.0 / 5.0;

	cout << "C\tF" << endl;
	cout << "------------" << endl;
	for (int celsius = 0; celsius < 21; celsius++)
	{
		fahrenheit = (CONVERSION * celsius) + 32;
		cout << celsius << "\t" << fahrenheit << endl;
	}
	return 0;
}
