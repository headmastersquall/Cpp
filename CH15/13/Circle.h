#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "BasicShape.h"

class Circle: public BasicShape
{
private:
	long int _centerX;
	long int _centerY;
	double _radius;
	void calcArea() override;
public:
	Circle(long int centerX, long int centerY, double radus)
	{
		_centerY = centerY;
		_centerX = centerX;
		_radius = radus;
		calcArea();
	}
	long int getCenterX() const { return _centerX; };
	long int getCenterY() const { return _centerY; };
	double getRadius() const { return _radius; };
};

#endif
