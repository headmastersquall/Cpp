/*
 * Monthly Sales Tax
 *
 * This program will prompt the user for the month, year,
 * and the amount of sales tax collected.  It will then
 * output a report that calculates the various forms of
 * tax based on the current tax rates.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	const double STATE_SALES_TAX_RATE = .04;
	const double COUNTY_SALES_TAX_RATE= .02;
	const int LABEL_WIDTH = 22;
	const int AMOUNT_WIDTH = 9;
 
	string month;
	int year;
	double amountCollected, sales, countyTax, stateTax;

	cout << "What year and months taxes are being calculated? ";
	cin >> year;
	cin >> month;
	cout << "What is the amount collected? ";
	cin >> amountCollected;
	cout << endl;

	countyTax = amountCollected * COUNTY_SALES_TAX_RATE;
	stateTax = amountCollected * STATE_SALES_TAX_RATE;
	sales = amountCollected - countyTax - stateTax;

	cout << "Date: " << month << " " << year << endl;
	cout << "--------------------" << endl;
	cout << setprecision(2) << fixed;
	cout << setw(LABEL_WIDTH) << left << "Total Collected:" << "$";
	cout << setw(AMOUNT_WIDTH) << right << amountCollected << endl;
	
	cout << setw(LABEL_WIDTH) << left << "Sales:" << "$";
	cout << setw(AMOUNT_WIDTH) << right << sales << endl;

	cout << setw(LABEL_WIDTH) << left << "County Sales Tax:" << "$";
	cout << setw(AMOUNT_WIDTH) << right << countyTax << endl;

	cout << setw(LABEL_WIDTH) << left << "State Sales Tax:" << "$";
	cout << setw(AMOUNT_WIDTH) << right << stateTax << endl;

	cout << setw(LABEL_WIDTH) << left << "Total Sales Tax:" << "$";
	cout << setw(AMOUNT_WIDTH) << right << stateTax + countyTax << endl;
	return 0;
}
