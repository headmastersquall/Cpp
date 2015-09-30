#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "BasicShape.h"

class Rectangle: public BasicShape {
private:
	long int _width;
	long int _length;
	void calcArea() override;
public:
	Rectangle(long int width, long int length)
		: BasicShape()
	{
		_width = width;
		_length = length;
		calcArea();
	}
	long int getWidth() const { return _width; };
	long int getLength() const { return _length; };
};

#endif
