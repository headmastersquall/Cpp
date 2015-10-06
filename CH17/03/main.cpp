/*
 * 17.03 List Copy Constructor
 *
 * Add a copy constructor to the linked list.
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
	cout << mylist.size() << " items in the list." << endl;
	mylist.printItems();
	cout << endl;

	cout << "Creating a copy of the list" << endl;
	LinkedList mylist2(mylist);
	cout << mylist2.size() << " items in the list." << endl;
	mylist2.printItems();
	cout << endl;

	cout << "Inserting 8 at index 2" << endl;
	mylist.insert(8, 2);
	cout << mylist.size() << " items in the list." << endl;
	mylist.printItems();
	cout << endl;

	cout << "Inserting 12 at index 0" << endl;
	mylist.insert(12, 0);
	cout << mylist.size() << " items in the list." << endl;
	mylist.printItems();
	cout << endl;

	cout << "Removing the first item in the list" << endl;
	mylist.remove(0);
	cout << mylist.size() << " items in the list." << endl;
	mylist.printItems();
	cout << endl;

	cout << "Removing the item at index 3" << endl;
	mylist.remove(3);
	cout << mylist.size() << " items in the list." << endl;
	mylist.printItems();
	cout << endl;

	try
	{
		cout << "Inserting an item out of range" << endl;
		mylist.insert(99, 100);
	}
	catch (const LinkedList::IndexOutOfRangeException &)
	{
		cout << "Index out of range when inserting a value." << endl;
		cout << endl;
	}

	try
	{
		cout << "Removing an item out of range" << endl;
		mylist.remove(100);
	}
	catch (const LinkedList::IndexOutOfRangeException &)
	{
		cout << "Index out of range when removing a value." << endl;
		cout << endl;
	}

	cout << "Clearing all items" << endl;
	mylist.clear();
	cout << mylist.size() << " items in the list." << endl;
	mylist.printItems();
	cout << endl;

	cout << "Inserting an 8 to index zero on an empty list" << endl;
	mylist.insert(8, 0);
	mylist.printItems();
	cout << endl;
	return 0;
}
