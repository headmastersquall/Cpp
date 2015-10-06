#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "LinkNode.h"
#include <iostream>

using namespace std;

template <class T>
class LinkedList {
private:
	int _size;
	LinkNode<T> *_head;
	LinkNode<T> *_tail;
public:
	LinkedList()
	{
		_size = 0;
		_head = nullptr;
		_tail = nullptr;
	}
	LinkedList(const LinkedList<T> &);
	~LinkedList();
	void clear();
	void append(T);
	void insert(T, int);
	void remove(int);
	void printItems() const;
	LinkNode<T>* head() const { return _head; };
	LinkNode<T>* tail() const { return _tail; };
	int size() const { return _size; };
	int search(T) const;

	class IndexOutOfRangeException {};
};

template <class T>
LinkedList<T>::LinkedList(const LinkedList &other)
{
	_size = 0;
	_head = nullptr;
	_tail = nullptr;

	LinkNode<T> *current = other->head();
	while(current != nullptr)
	{
		append(current->value);
		current = current->next;
	}
}

template <class T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template <class T>
void LinkedList<T>::clear()
{
	LinkNode<T> *current = _head;
	LinkNode<T> *next = nullptr;

	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;
	}
	_head = nullptr;
	_tail = nullptr;
	_size = 0;
}

template <class T>
void LinkedList<T>::append(T value)
{
	LinkNode<T> *newNode = new LinkNode<T>(value);

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

template <class T>
void LinkedList<T>::insert(T value, int index)
{
	LinkNode<T> *current = _head;
	LinkNode<T> *previous = nullptr;
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

	LinkNode<T> *newItem;
	newItem = new LinkNode<T>(value);
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

template <class T>
void LinkedList<T>::remove(int index)
{
	LinkNode<T> *current = _head;
	LinkNode<T> *previous = nullptr;
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

	LinkNode<T> *nextItem;
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

template <class T>
int LinkedList<T>::search(T value) const
{
	int index = 0;
	LinkNode<T> *current = _head;

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

template <class T>
void LinkedList<T>::printItems() const
{
	LinkNode<T> *current = _head;
	while (current != nullptr)
	{
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
}

#endif
