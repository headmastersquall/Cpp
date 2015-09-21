/*
 * 13.03 Car Class
 *
 * Works with a Car class that keeps track of speed and allows the user to
 * accelerate and decelerate.
 */

#include "Car.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int TIMES = 5;

	Car myCar(2015, "Tesla");

	cout << "Accelerating" << endl;
	for (int i = 0; i < TIMES; i++)
	{
		myCar.accelerate();
		cout << "Speed: " << myCar.getSpeed() << endl;
	}

	cout << "Braking" << endl;
	for (int i = 0; i < TIMES; i++)
	{
		myCar.brake();
		cout << "Speed: " << myCar.getSpeed() << endl;
	}
}
