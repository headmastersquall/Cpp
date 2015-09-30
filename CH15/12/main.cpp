/*
 * 15.12 Ship, CruiseShip, and CargoShip Classes
 *
 * Create an inheritance structure for various ships.
 */

#include <iostream>
#include <string>
#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"

using namespace std;

int main()
{
	Ship ship("Black Perl", 1746);
	ship.print();

	CruiseShip cruiseShip("Carnival", 1997, 4000);
	cruiseShip.print();

	CargoShip cargoShip("The Box", 1965, 40);
	cargoShip.print();
	return 0;
}
