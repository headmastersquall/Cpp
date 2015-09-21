/*
 * 06. Kinetic Energy
 *
 * Calculates the kinetic energy an object has.
 */

#include <iostream>

using namespace std;

double kineticEnergy(double m, double v)
{
	return .5 * m * v * v;
}

int main()
{
	double mass, velosity;
	cout << "What is the mass in kilograms? ";
	cin >> mass;
	cout << "What is the velisity in meters per second? ";
	cin >> velosity;
	cout << "The kinetic energy calculated to be: "
		 << kineticEnergy(mass, velosity) << endl;
	return 0;
}
