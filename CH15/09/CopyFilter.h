#ifndef COPYFILTER_H_
#define COPYFILTER_H_

#include "AbstractFileFilter.h"

class CopyFilter : public AbstractFileFilter
{
public:
	CopyFilter() {};
protected:
	char transform(char c) const override { return c; };
};

#endif
