#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    const double TAX_RATE = 7.0;
    double item1 = 15.95,
          item2 = 24.95,
          item3 = 6.95,
          item4 = 12.95,
          item5 = 3.95;
    double subtotal = item1 + item2 + item3 + item4 + item5;
    double tax = subtotal / TAX_RATE;
    cout << "Price of item 1 = $" << item1 << endl;
    cout << "Price of item 2 = $" << item2 << endl;
    cout << "Price of item 3 = $" << item3 << endl;
    cout << "Price of item 4 = $" << item4 << endl;
    cout << "Price of item 5 = $" << item5 << endl;
    cout << endl;
    cout << "Subtotal: " << subtotal << endl;
    cout << "Sales Tax: " << tax << endl;
    cout << "Total: " << subtotal + tax << endl;
    return 0;
}
