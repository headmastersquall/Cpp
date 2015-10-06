#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "LinkNode.h"

class LinkedList {
private:
	int _size;
	LinkNode *head;
	LinkNode *tail;
public:
	LinkedList()
	{
		_size = 0;
		head = nullptr;
		tail = nullptr;
	}
	~LinkedList();
	void clear();
	void append(int);
	void insert(int, int);
	void remove(int);
	void printItems();
	int size() const { return _size; };

	class IndexOutOfRangeException {};
};

#endif
