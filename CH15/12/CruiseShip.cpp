#include "CruiseShip.h"
#include <iostream>

using namespace std;

void CruiseShip::print() const
{
	cout << "The " << getName() << " has a max passenger capacity of "
		 << _maxPassengers << endl;
}
