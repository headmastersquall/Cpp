#include <iostream>
#include "LinkedList.h"
#include "LinkNode.h"

using namespace std;

LinkedList::LinkedList(const LinkedList &other)
{
	_size = 0;
	_head = nullptr;
	_tail = nullptr;

	LinkNode *current = other.head();
	while(current != nullptr)
	{
		append(current->value);
		current = current->next;
	}
}

LinkedList::~LinkedList()
{
	clear();
}

void LinkedList::clear()
{
	LinkNode *current = _head;
	LinkNode *next = nullptr;

	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;
	}
	_head = nullptr;
	_tail = _head;
	_size = 0;
}

void LinkedList::append(int value)
{
	LinkNode *newNode = new LinkNode(value);

	if (!_head)
	{
		_head = newNode;
		_tail = newNode;
	}
	else
	{
		_tail->next = newNode;
		_tail = _tail->next;
	}
	_size += 1;
}

void LinkedList::insert(int value, int index)
{
	LinkNode *current = _head;
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
		newItem->next = _head;
		_head = newItem;
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
	LinkNode *current = _head;
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
		nextItem = _head->next;
		delete _head;
		_head = nextItem;
	}
	else
	{
		nextItem = current->next;
		delete current;
		previous->next = nextItem;
	}
	_size -= 1;
}

int LinkedList::search(int value) const
{
	int index = 0;
	LinkNode *current = _head;

	while(current != nullptr)
	{
		if (current->value == value)
		{
			return index;
		}
		current = current->next;
		index += 1;
	}
	return -1;
}

void LinkedList::printItems() const
{
	LinkNode *current = _head;
	while (current != nullptr)
	{
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
}
