#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const double A_SEAT_COST = 15.0;
	const double B_SEAT_COST = 12.0;
	const double C_SEAT_COST = 9.0;

	int aSeatCount, bSeatCount, cSeatCount;
	double aSeatSales, bSeatSales, cSeatSales;

	cout << "How many A seats? ";
	cin >> aSeatCount;
	cout << "How many B seats? ";
	cin >> bSeatCount;
	cout << "How many C seats? ";
	cin >> cSeatCount;

	aSeatSales = aSeatCount * A_SEAT_COST; 
	bSeatSales = bSeatCount * B_SEAT_COST; 
	cSeatSales = cSeatCount * C_SEAT_COST; 

	cout << endl << "Sales:" << endl;
	cout << setprecision(2) << fixed;
	cout << "A sales: $" << aSeatSales << endl;
	cout << "B sales: $" << bSeatSales << endl;
	cout << "C sales: $" << cSeatSales << endl;
	cout << "Total: $" << aSeatSales + bSeatSales + cSeatSales << endl;
	return 0;
}
