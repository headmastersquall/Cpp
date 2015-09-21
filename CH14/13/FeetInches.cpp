#include "FeetInches.h"
#include <cstdlib>

FeetInches FeetInches::multiply(const FeetInches &fi) const
{
	FeetInches tmp(
			getFeet() * fi.getFeet(),
			getInches() * fi.getInches());
	return tmp;
}

FeetInches FeetInches::operator +(const FeetInches &fi)
{
	FeetInches tmp(
			getFeet() + fi.getFeet(),
			getInches() + fi.getInches());
	return tmp;
}

FeetInches FeetInches::operator -(const FeetInches &fi)
{
	int inches = abs(fi.getAsInches() - _inches);
	FeetInches tmp(0, inches);
	return tmp;
}

FeetInches FeetInches::operator ++()
{
	FeetInches tmp(0, _inches + 1);
	return tmp;
}

FeetInches FeetInches::operator ++(int)
{
	FeetInches tmp(0, _inches);
	_inches += 1;
	return tmp;
}

FeetInches FeetInches::operator --()
{
	int inches = _inches == 0 ? 0 : _inches - 1;
	FeetInches tmp(0, inches);
	return tmp;
}

FeetInches FeetInches::operator --(int)
{
	FeetInches tmp(0, _inches);
	_inches = _inches == 0 ? 0 : _inches - 1;
	return tmp;
}

bool FeetInches::operator >(const FeetInches &fi)
{
	return _inches > fi.getAsInches();
}

bool FeetInches::operator <(const FeetInches &fi)
{
	return _inches < fi.getAsInches();
}

bool FeetInches::operator ==(const FeetInches &fi)
{
	return _inches == fi.getAsInches();
}

bool FeetInches::operator >=(const FeetInches &fi)
{
	return _inches >= fi.getAsInches();
}

bool FeetInches::operator <=(const FeetInches &fi)
{
	return _inches <= fi.getAsInches();
}

bool FeetInches::operator !=(const FeetInches &fi)
{
	return _inches != fi.getAsInches();
}
