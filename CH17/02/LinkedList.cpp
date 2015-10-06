#include <iostream>
#include "LinkedList.h"
#include "LinkNode.h"

using namespace std;

LinkedList::~LinkedList()
{
	clear();
}

void LinkedList::clear()
{
	LinkNode *current = head;
	LinkNode *next = nullptr;

	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
	tail = head;
	_size = 0;
}

void LinkedList::append(int value)
{
	LinkNode *newNode = new LinkNode(value);

	if (!head)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = tail->next;
	}
	_size += 1;
}

void LinkedList::insert(int value, int index)
{
	LinkNode *current = head;
	LinkNode *previous = nullptr;
	int currentIndex = 0;

	if (index < 0 || index > _size)
	{
		throw IndexOutOfRangeException();
	}

	while (currentIndex++ != index)
	{
		previous = current;
		current = current->next;
	}

	LinkNode *newItem;
	newItem = new LinkNode(value);
	if (index == 0)
	{
		newItem->next = head;
		head = newItem;
	}
	else
	{
		newItem->next = current;
		previous->next = newItem;
	}
	_size += 1;
}

void LinkedList::remove(int index)
{
	LinkNode *current = head;
	LinkNode *previous = nullptr;
	int currentIndex = 0;

	if (index < 0 || index > _size)
	{
		throw IndexOutOfRangeException();
	}

	if (_size == 0)
	{
		return;
	}

	while (currentIndex++ != index)
	{
		previous = current;
		current = current->next;
	}

	LinkNode *nextItem;
	if (index == 0)
	{
		nextItem = head->next;
		delete head;
		head = nextItem;
	}
	else
	{
		nextItem = current->next;
		delete current;
		previous->next = nextItem;
	}
	_size -= 1;
}

void LinkedList::printItems()
{
	LinkNode *current = head;
	while (current != nullptr)
	{
		cout << current->nodeValue << " ";
		current = current->next;
	}
	cout << endl;
}
