#include "AbstractFileFilter.h"
#include <fstream>

void AbstractFileFilter::doFilter(ifstream &in, ofstream &out) const
{
	char c;
	while (true)
	{
		in.read(&c, 1);
		if (in.eof())
		{
			break;
		}
		c = transform(c);
		out.write(&c, 1);
	}
}
