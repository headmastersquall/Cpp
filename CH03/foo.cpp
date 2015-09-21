#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const double COST_PER_CUBIC_FOOT = 0.23;
	const double CHARGE_PER_CUBIC_FOOT = 0.5;

	double length, width, height, volume, cost, charge, profit;

	cout << "Enter the length, width and height of the crate" << endl;
	cout << "Separate each value by spaces." << endl;

	cin >> length;
	cin >> width;
	cin >> height;

	volume = length * width * height;
	cost = COST_PER_CUBIC_FOOT * volume;
	charge = CHARGE_PER_CUBIC_FOOT * volume;
	profit = charge - cost;

	cout << "Invoice" << endl;
	cout << "-------" << endl;
	cout << setprecision(2) << fixed;
	cout << "Volume: " << volume << " Cubic Feet" << endl;
	cout << "Cost: $" << cost << endl;
	cout << "Charge: $" << charge << endl;
	cout << "Profit: $" << profit << endl;
	
	return 0;
}
