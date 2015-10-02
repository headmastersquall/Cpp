/*
 * 15.01 Employee and ProductionWorker Classes
 *
 * Show an inheritance structure between an Employee and a ProductionWorker.
 */

#include <iostream>
#include "ProductionWorker.h"

using namespace std;

void showWorker(ProductionWorker worker)
{
	printf("Employee Number: %i\n", worker.getEmployeeNumber());
	printf("Name: %s\n", worker.getName().c_str());
	printf("Hire Date: %s\n", worker.getHireDate().c_str());
	printf("Shift: %s\n", worker.getShift() == Day ? "Day" : "Night");
	printf("Hourly Pay Rate: %.2f\n", worker.getHourlyPayRate());
}

int main()
{
	try
	{
		// Good worker
		//ProductionWorker worker("Chris", 4928, "01/29/1999", Day, 14.90);

		// Bad employeeNumber
		//ProductionWorker worker("Steve", 21043, "02/05/2012", Night, 11.15);

		// Bad pay rate
		ProductionWorker worker("Chad", 5832, "07/19/2000", Day, -10.00);
		showWorker(worker);
		return 0;
	}
	catch (const Employee::InvalidEmployeeNumberException &e)
	{
		printf("Invalid employee number %i\n", e.getEmployeeNumber());
	}
	catch (const ProductionWorker::InvalidPayRateException &e)
	{
		printf("Pay rate cannot be negative (%.2f)\n", e.getPayRate());
	}
}
