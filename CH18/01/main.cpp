/*
 * 18.01 Static Stack Template
 *
 * Implements a static stack that can work with any data type.
 */

#include <iostream>
#include "StaticStack.h"

using namespace std;

int main()
{
	cout << "Adding 5, 9 and 2 to the stack" << endl;
	StaticStack<int> stack(3);
	stack.push(5);
	stack.push(9);
	stack.push(2);
	cout << stack.size() << " items in the stack" << endl;

	cout << "Popping all items off the stack" << endl;
	while (!stack.isEmpty())
	{
		cout << stack.pop() << endl;
	}
	cout << stack.size() << " items in the stack" << endl;

	try
	{
		cout << "Filling the stack past it's capacity" << endl;
		stack.push(1);
		stack.push(1);
		stack.push(1);
		stack.push(1);
	}
	catch (const StaticStack<int>::FullStackException &e)
	{
		cout << "Cannot add items to a full stack" << endl;
	}

	try
	{
		cout << "Popping item from an empty stack" << endl;
		stack.clear();
		stack.pop();
	}
	catch (const StaticStack<int>::EmptyStackException &e)
	{
		cout << "Cannot remove from an empty stack" << endl;
	}
	return 0;
}
