/*
 * 20.02 Node Counter
 *
 * Demonstrates a function on the binary tree that counts the number
 * of nodes it contains.
 */

#include "BTree.h"
#include <iostream>

using namespace std;

int main()
{
	BTree<int> tree;

	cout << "With an empty tree" << endl;
	cout << "Item count: " << tree.count() << endl;

	cout << "Adding three items to the tree" << endl;
	tree.add(4);
	tree.add(9);
	tree.add(7);
	cout << "Item count: " << tree.count() << endl;

	cout << "Clearing the tree" << endl;
	tree.clear();
	cout << "Item count: " << tree.count() << endl;

	cout << "Adding items to the tree" << endl;
	tree.add(10);
	tree.add(11);
	tree.add(3);
	tree.add(17);
	tree.add(8);
	tree.add(12);
	cout << "Does the tree contain the value 17? " << tree.hasValue(17) << endl;
	cout << "Can I find the number 11? " << tree.find(11) << endl;

	cout << "Show all items in the tree" << endl;
	tree.foreach([](int value) { cout << value << " ";});
	return 0;
}
