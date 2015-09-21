#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    const double TAX_RATE = 6.75;
    const double TIP_RATE = 0.2;
    double charge = 8.867E1;
    double tax = charge / TAX_RATE;
    double tip = tax * TIP_RATE;
    
    cout << "Cost of the meal: $" << charge << endl;
    cout << "Tax: $" << tax << endl;
    cout << "Tip: $" << tip << endl;
    cout << "Total: $" << charge + tax + tip << endl;
    return 0;
}
