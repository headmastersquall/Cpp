/*
 * 05. Falling Distance
 *
 * Shows how far an object has fallen in the given amount of seconds.
 */

#include <iostream>

using namespace std;

double fallingDistance(double seconds);

int main()
{
	cout << "Sec\tDist" << endl;
	for (int i = 1; i < 11; i++)
	{
		cout << i << "\t" << fallingDistance(i) << endl;
	}
	return 0;
}

double fallingDistance(double seconds)
{
	return .5 * 9.8 * (seconds * 2);
}
