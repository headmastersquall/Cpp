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
		if (hourlyPayRate < 0)
		{
			throw InvalidPayRateException(hourlyPayRate);
		}
		_shift = shift;
		_hourlyPayRate = hourlyPayRate;
	};
	Shift getShift() const { return _shift; };
	double getHourlyPayRate() const { return _hourlyPayRate; };

	class InvalidPayRateException
	{
	private:
		double _payRate;
	public:
		InvalidPayRateException(double payRate)
		{
			_payRate = payRate;
		}
		double getPayRate() const { return _payRate; };
	};
};

#endif
