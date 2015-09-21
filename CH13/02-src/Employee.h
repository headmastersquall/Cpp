#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee
{
private:
	string _name;
	int _idNumber;
	string _department;
	string _position;

public:
	Employee(string name, int idNumber, string deparment, string position)
		{
			_name = name;
			_idNumber = idNumber;
			_department = deparment;
			_position = position;
		}
	Employee(string name, int idNumber)
		{
			_name = name;
			_idNumber = idNumber;
			_department = "";
			_position = "";
		}
	Employee()
		{
			_name = "";
			_idNumber = 0;
			_department = "";
			_position = "";
		}
	string getName() { return _name; }
	int getIdNumber() { return _idNumber; }
	string getDepartment() { return _department; }
	string getPosition() { return _position; }
	void setName(string name) { _name = name; }
	void setIdNumber(int idNumber) { _idNumber = idNumber; }
	void setDepartment(string department) { _department = department; }
	void setPosition(string position) { _position = position; }
};

#endif
