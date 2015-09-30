#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>

using namespace std;

class Employee
{
private:
	string _name;
	int _employeeNumber;
	string _hireDate;
public:
	Employee(string name, int employeeNumber, string hireDate)
	{
		_name = name;
		_employeeNumber = employeeNumber;
		_hireDate = hireDate;
	};
	string getName() const { return _name; };
	int getEmployeeNumber() const { return _employeeNumber; };
	string getHireDate() const { return _hireDate; };
};

#endif
