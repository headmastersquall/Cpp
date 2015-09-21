#include "NumDays.h"

NumDays NumDays::operator +(double hours)
{
	NumDays newNumDays(_hours + hours);
	return newNumDays;
}

NumDays NumDays::operator -(double hours)
{
	double newHours = _hours - hours;
	if (newHours < 0)
	{
		newHours = 0;
	}
	NumDays newNumDays(newHours);
	return newNumDays;
}

NumDays NumDays::operator ++()
{
	_hours += 1;
	return *this;
}

NumDays NumDays::operator ++(int)
{
	NumDays origNumDays(_hours);
	_hours += 1;
	return origNumDays;
}

NumDays NumDays::operator --()
{
	decHours();
	return *this;
}

NumDays NumDays::operator --(int)
{
	NumDays origNumDays(_hours);
	decHours();
	return origNumDays;
}

void NumDays::decHours()
{
	_hours = _hours == 0 ? 0 : _hours - 1;
}
