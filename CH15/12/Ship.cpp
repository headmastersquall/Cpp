#include <iostream>
#include "Ship.h"

using namespace std;

void Ship::print() const
{
	cout << "The ship " << _name << " was built in " << _year << endl;
}
