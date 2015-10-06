/*
 * 17.08 List Template
 *
 * Convert the list to use a template for generic values.
 */

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<int> mylist;
	cout << "Adding items to list" << endl;

	mylist.append(1);
	mylist.append(2);
	mylist.append(3);
	cout << "Values in my list are" << endl;
	mylist.printItems();
	cout << "The value 2 is at index " << mylist.search(2) << endl;
	cout << "The value 8 is at index " << mylist.search(8) << endl;

	LinkedList<double> mylist2;
	cout << "Adding items to list" << endl;
	mylist2.append(1.5);
	mylist2.append(2.2);
	mylist2.append(5.3);
	mylist2.insert(9.4, 2);
	cout << "Values in my list are" << endl;
	mylist2.printItems();
	cout << "The value 1.5 is at index " << mylist.search(1.5) << endl;
	cout << "The value 8 is at index " << mylist.search(8) << endl;

	return 0;
}
