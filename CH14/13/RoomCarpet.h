#ifndef ROOMCARPET_H_
#define ROOMCARPET_H_

#include "RoomDimensions.h"

class RoomCarpet
{
private:
	RoomDimensions _roomDimensions;
	double _carpetCostPerInch;
public:
	RoomCarpet(RoomDimensions dimensions, double cost)
	{
		_roomDimensions = dimensions;
		_carpetCostPerInch = cost / 12;
	}
	RoomDimensions getRoomDimensions() const { return _roomDimensions; };
	double getCarpetCost() const;
	double getTotalCost() const;
};

#endif
