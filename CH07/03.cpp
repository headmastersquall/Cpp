/*
 * 03. Chips and Salsa
 *
 * Keeps track of salsa sales by a salsa type.
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int jarCountPrompt(string);
void showSalesTotals(string[], int[], int);

int main()
{
	const int TYPE_COUNT = 5;
	string salsaTypes[] = {
		"mild",
		"medium",
		"sweet",
		"hot",
		"zesty"
	};
	int salesCount[TYPE_COUNT];
	cout << "Enter the salsa sales for the past month:" << endl;
	for (int i = 0; i < TYPE_COUNT; i++)
	{
		salesCount[i] = jarCountPrompt(salsaTypes[i]);
	}
	showSalesTotals(salsaTypes, salesCount, TYPE_COUNT);
	return 0;
}

int jarCountPrompt(const string salsaType)
{
	int value;
	cout << "Number of " << salsaType << " salsa jars sold: ";
	cin >> value;
	if (value < 0)
	{
		cout << "Jar count cannot be negative." << endl;
		return jarCountPrompt(salsaType);
	}
	return value;
}

void showSalesTotals(string salsaTypes[], int sales[], const int typeCount)
{
	int lowestSaleIndex = 0;
	int highestSaleIndex = 0;
	int totalSales = 0;
	
	cout << "Salsa sales totals" << endl;
	for (int i = 0; i < typeCount; i++)
	{
		lowestSaleIndex = sales[i] < sales[lowestSaleIndex]
			? i
			: lowestSaleIndex;
		highestSaleIndex = sales[i] > sales[highestSaleIndex]
			? i
			: highestSaleIndex;
		totalSales += sales[i];
		
		cout << salsaTypes[i] << ": " << sales[i] << endl;
	}
	
	cout << endl
		 << "Highest sale: " << salsaTypes[highestSaleIndex] << endl
		 << "Lowest sale:  " << salsaTypes[lowestSaleIndex] << endl
		 << "Total sales:  " << totalSales << endl;	
}

