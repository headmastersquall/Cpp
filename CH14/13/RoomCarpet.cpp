#include "RoomCarpet.h"

double RoomCarpet::getCarpetCost() const
{
	return _carpetCostPerInch * 12;
}

double RoomCarpet::getTotalCost() const
{
	return _carpetCostPerInch * _roomDimensions.getArea().getAsInches();
}
