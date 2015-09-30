#ifndef ABSTRACTFILEFILTER_H_
#define ABSTRACTFILEFILTER_H_

#include <fstream>

using namespace std;

class AbstractFileFilter
{
public:
	AbstractFileFilter() {};
	virtual ~AbstractFileFilter() {};
	void doFilter(ifstream &in, ofstream &out) const;
protected:
	virtual char transform(char ch) const = 0;
};

#endif
