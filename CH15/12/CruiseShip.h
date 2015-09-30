#ifndef CRUISESHIP_H_
#define CRUISESHIP_H_

#include "Ship.h"

class CruiseShip: public Ship {
private:
	int _maxPassengers;
public:
	CruiseShip(string name, int year, int maxPassengers)
		: Ship(name, year)
	{
		_maxPassengers = maxPassengers;
	}
	~CruiseShip() {};
	int getMaxPassengers() { return _maxPassengers; };
	void print() const override;
};

#endif
