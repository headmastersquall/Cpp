#ifndef CARGOSHIP_H_
#define CARGOSHIP_H_

#include "Ship.h"

class CargoShip: public Ship {
private:
	int _tonnageCapacity;
public:
	CargoShip(string name, int year, int tonnageCapacity)
		: Ship(name, year)
	{
		_tonnageCapacity = tonnageCapacity;
	}
	~CargoShip() {};
	int getTonnageCapacity() { return _tonnageCapacity; };
	void print() const override;
};

#endif
