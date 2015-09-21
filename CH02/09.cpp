#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "The following show the size of the data types:" << endl;
	cout << setw(8) << "char: " << sizeof(char) << endl;
	cout << setw(8) << "int: " << sizeof(int) << endl;
	cout << setw(8) << "float: " << sizeof(float) << endl;
	cout << setw(8) << "double: " << sizeof(double) << endl;
	return 0;
}
