/*
 * 15.01 Employee and ProductionWorker Classes
 *
 * Show an inheritance structure between an Employee and a ProductionWorker.
 */

#include <iostream>
#include "ProductionWorker.h"

using namespace std;

int main()
{
	ProductionWorker worker("Chris", 4928, "01/29/1999", Day, 14.90);

	printf("Employee Number: %i\n", worker.getEmployeeNumber());
	printf("Name: %s\n", worker.getName().c_str());
	printf("Hire Date: %s\n", worker.getHireDate().c_str());
	printf("Shift: %s\n", worker.getShift() == Day ? "Day" : "Night");
	printf("Hourly Pay Rate: %.2f\n", worker.getHourlyPayRate());
	return 0;
}
