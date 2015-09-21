#include "DivSales.h"

double DivSales::totalCorporateSales = 0;

DivSales::DivSales(double q1, double q2, double q3, double q4)
{
	quarterlySales[0] = q1 < 0 ? 0 : q1;
	quarterlySales[1] = q2 < 0 ? 0 : q2;
	quarterlySales[2] = q3 < 0 ? 0 : q3;
	quarterlySales[3] = q4 < 0 ? 0 : q4;
	totalCorporateSales += (q1 + q2 + q3 + q4);
}

double DivSales::getSalesForQuarter(int quarter)
{
	return quarterlySales[quarter - 1];
}
