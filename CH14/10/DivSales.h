#ifndef DIVSALES_H
#define DIVSALES_H

const int NUMBER_OF_QUARTERS = 4;

class DivSales
{
private:
	double quarterlySales[NUMBER_OF_QUARTERS];
public:
	DivSales(double q1 = 0, double q2 = 0, double q3 = 0, double q4 = 0);
	static double totalCorporateSales;
	double getSalesForQuarter(int quarter);
};

#endif
