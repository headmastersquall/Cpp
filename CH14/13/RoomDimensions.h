#ifndef ROOMDIMENSIONS_H_
#define ROOMDIMENSIONS_H_

#include "FeetInches.h"

class RoomDimensions
{
private:
	FeetInches _width;
	FeetInches _length;
public:
	RoomDimensions(FeetInches width = {0, 0}, FeetInches length = {0, 0})
	{
		_width = width;
		_length = length;
	}
	FeetInches getArea() const { return _width.multiply(_length); };
	FeetInches getWidth() const { return _width; };
	FeetInches getLength() const { return _length; };
};

#endif
