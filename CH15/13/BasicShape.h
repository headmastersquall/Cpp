#ifndef BASICSHAPE_H_
#define BASICSHAPE_H_

class BasicShape
{
public:
	BasicShape() { _area = 0; };
	virtual ~BasicShape() {};
	double getArea() { return _area; };
protected:
	double _area;
	virtual void calcArea() = 0;
};

#endif
