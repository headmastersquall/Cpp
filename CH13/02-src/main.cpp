/*
 * 13.01 Date
 *
 * Creates a custom date class that formats the date three different ways.
 */

#include "Employee.h"
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	const int EMPLOYEE_COUNT = 3;
	Employee employees[EMPLOYEE_COUNT]
	{
		{ "Susan Meyers", 47899, "Accounting", "Vice President" },
		{ "Mark Jones", 39119, "IT", "Programmer" },
		{ "Joy Rogers", 81774, "Manufacturing", "Engineer" }
	};

	const char* headerFormat = "%-14s %-14s %-14s %-14s\n";
	const char* bodyFormat = "%-14s %-14i %-14s %-14s\n";

	printf(headerFormat, "Name", "ID", "Department", "Position");
	for (int i = 0; i < EMPLOYEE_COUNT; i++)
	{
		printf(bodyFormat,
				employees[i].getName().c_str(),
				employees[i].getIdNumber(),
				employees[i].getDepartment().c_str(),
				employees[i].getPosition().c_str());
	}
	return 0;
}
