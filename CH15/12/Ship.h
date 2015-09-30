#ifndef SHIP_H_
#define SHIP_H_

#include <string>

using namespace std;

class Ship {
private:
	string _name;
	int _year;
public:
	Ship(string name, int year)
	{
		_name = name;
		_year = year;
	};
	virtual ~Ship() {};
	virtual void print() const;
	string getName() const { return _name; };
	int getYear() const { return _year; };
};

#endif
