/*
 * 18.04 Dynamic Queue Template
 *
 * Implements a dynamic queue that can work with any data type.
 */

#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	Queue<int> queue;
	cout << "Add 1, 2, 3 to the queue" << endl;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	cout << "There are " << queue.size() << " items in the queue" << endl;

	cout << "Remove the items from the queue" << endl;
	while (!queue.isEmpty())
	{
		cout << queue.dequeue() << endl;
	}
	cout << "There are " << queue.size() << " items in the queue" << endl;

	try
	{
		cout << "Dequeuing an item from an empty queue throws an exception" << endl;
		queue.dequeue();
	}
	catch (const Queue<int>::EmptyQueueException &e)
	{
		cout << "Cannot dequeue on an empty queue" << endl;
	}
	return 0;
}
