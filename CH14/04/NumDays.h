#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays
{
private:
	const double HOURS_PER_WORK_DAY = 8.0;
	double _hours;
	void decHours();
public:
	NumDays(double hours) { _hours = hours; };
	double getWorkDays() { return _hours / HOURS_PER_WORK_DAY; }
	double getWorkHours() { return _hours; }
	NumDays operator+ (const double hours);
	NumDays operator- (const double hours);
	NumDays operator++ ();
	NumDays operator++ (int);
	NumDays operator-- ();
	NumDays operator-- (int);
};
#endif
