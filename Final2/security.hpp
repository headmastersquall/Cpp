#ifndef SECURITY_HPP
#define SECURITY_HPP

#include <string>

using namespace std;

void delay();
string generate_uuid();
string getPassPhrase();
string sha512(const char* input);

#endif
