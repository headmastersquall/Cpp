#ifndef ENCRYPTIONFILTER_H_
#define ENCRYPTIONFILTER_H_

#include "AbstractFileFilter.h"

class EncryptionFilter : public AbstractFileFilter
{
private:
	int _key;
public:
	EncryptionFilter(int key) { _key = key; };
protected:
	char transform(char c) const override { return c + _key; };
};

#endif
