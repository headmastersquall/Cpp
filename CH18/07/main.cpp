/*
 * 17.07 Dynamic MathStack
 *
 * Create a dynamic stack that performs math calculations on the values it holds.
 */

#include <iostream>
#include "MathStack.h"

using namespace std;

int main()
{
	MathStack<int> stack;
	stack.push(5);
	stack.push(7);
	stack.add();
	cout << "5 + 7 = " << stack.pop() << endl;

	stack.push(12);
	stack.push(9);
	stack.sub();
	cout << "12 - 9 = " << stack.pop() << endl;

	stack.push(9);
	stack.push(50);
	stack.mult();
	cout << "9 * 50 = " << stack.pop() << endl;

	stack.push(20);
	stack.push(2);
	stack.div();
	cout << "20 / 2 = " << stack.pop() << endl;

	for (int i = 1; i < 11; i++)
	{
		stack.push(i);
	}
	stack.addAll();
	cout << "Adding numbers from 1 to 10 = " << stack.pop() << endl;

	stack.push(10);
	stack.push(10);
	stack.push(10);
	stack.multAll();
	cout << "10 * 10 * 10 = " << stack.pop() << endl;
	return 0;
}
