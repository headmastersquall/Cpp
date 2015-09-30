#include "CargoShip.h"
#include <iostream>

using namespace std;

void CargoShip::print() const
{
	cout << "The " << getName() << " has a cargo capacity of "
		 << _tonnageCapacity << " tones." << endl;
}
