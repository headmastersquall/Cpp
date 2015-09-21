#ifndef CAR_H
#define CAR_H

#include <string>

using namespace std;

class Car
{
private:
	int _yearModel;
	string _make;
	int _speed;
public:
	Car(int year, string make)
		{
			_yearModel = year;
			_make = make;
			_speed = 0;
		}
	int getYear() const { return _yearModel; }
	string getMake() const { return _make; }
	int getSpeed() const { return _speed; }
	void accelerate();
	void brake();
};

#endif
