/*
 * 14.10 Corporate Sales
 *
 * Defines a class to capture the quarterly sales of a corporations devision.
 */

#include "DivSales.h"
#include <iostream>

using namespace std;

void promptForSales(const int divisions, DivSales *sales)
{
	const char promptFmt[] = "Enter sales of quarter %d for division %d: ";
	double q1, q2, q3, q4 = 0;

	for (int divIndex = 0; divIndex < divisions; divIndex++)
	{
		printf(promptFmt, 1, divIndex + 1);
		cin >> q1;
		printf(promptFmt, 2, divIndex + 1);
		cin >> q2;
		printf(promptFmt, 3, divIndex + 1);
		cin >> q3;
		printf(promptFmt, 4, divIndex + 1);
		cin >> q4;
		sales[divIndex] = { q1, q2, q3, q4 };
	}
}

void showSalesTable(const int divisions, DivSales *sales)
{
	const char headerFmt[] = "%10s%12s%12s%12s%12s\n";
	const char rowFmt[] = "%10d%12.2f%12.2f%12.2f%12.2f\n";

	printf(headerFmt, "Division", "Q1", "Q2", "Q3", "Q4");
	for (int i = 0; i < divisions; i++)
	{
		printf(
			rowFmt,
			i + 1,
			sales[i].getSalesForQuarter(1),
			sales[i].getSalesForQuarter(2),
			sales[i].getSalesForQuarter(3),
			sales[i].getSalesForQuarter(4));
	}
	printf("Total Corporate Sales: $%.2f", sales->totalCorporateSales);
}

int main()
{
	const int DIVISIONS = 6;
	DivSales corporateSales[DIVISIONS];
	promptForSales(DIVISIONS, corporateSales);
	showSalesTable(DIVISIONS, corporateSales);
	return 0;
}
