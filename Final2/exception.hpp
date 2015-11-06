#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <string>

using namespace std;

class Exception {
private:
	string _message;
public:
	Exception(string message) { _message = message; };
	string getMessage() const { return _message; };
};

#endif
