#ifndef UPPERCASEFILTER_H_
#define UPPERCASEFILTER_H_

#include "AbstractFileFilter.h"
#include <cstdlib>

class UpperCaseFilter : public AbstractFileFilter
{
public:
	UpperCaseFilter() {};
protected:
	char transform(char c) const override { return toupper(c); };
};

#endif
