/*
 * 17.05 List Search
 *
 * Add a search method to the Linked List.
 */

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList mylist;
	cout << "Adding items to list" << endl;
	mylist.append(1);
	mylist.append(2);
	mylist.append(3);
	cout << "Values in my list are" << endl;
	mylist.printItems();
	cout << "The value 2 is at index " << mylist.search(2) << endl;
	cout << "The value 8 is at index " << mylist.search(8) << endl;

	return 0;
}
