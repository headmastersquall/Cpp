#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "LinkNode.h"

class LinkedList {
private:
	int _size;
	LinkNode *_head;
	LinkNode *_tail;
public:
	LinkedList()
	{
		_size = 0;
		_head = nullptr;
		_tail = nullptr;
	}
	LinkedList(const LinkedList &);
	~LinkedList();
	void clear();
	void append(int);
	void insert(int, int);
	void remove(int);
	void printItems() const;
	LinkNode* head() const { return _head; };
	LinkNode* tail() const { return _tail; };
	int size() const { return _size; };

	class IndexOutOfRangeException {};
};

#endif
