#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int a = 28,
         b = 32,
         c = 37,
         d = 24,
         e = 33;
    double sum = a + b + c + d + e;
    cout << "The average of the five numbers is: ";
    cout << sum / 5;
    cout << endl;
    return 0;
}
