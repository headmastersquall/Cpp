#ifndef PRODUCTIONWORKER_H_
#define PRODUCTIONWORKER_H_

#include "Employee.h"
#include <string>

using namespace std;

enum Shift
{
	Day = 1,
	Night = 2
};

class ProductionWorker : public Employee
{
private:
	Shift _shift;
	double _hourlyPayRate;
public:
	ProductionWorker(
			string name,
			int employeeNumber,
			string dateHired,
			Shift shift,
			double hourlyPayRate) : Employee(name, employeeNumber, dateHired)
	{
		_shift = shift;
		_hourlyPayRate = hourlyPayRate;
	};
	Shift getShift() const { return _shift; };
	double getHourlyPayRate() const { return _hourlyPayRate; };
};

#endif
