#ifndef QUEUE_H_
#define QUEUE_H_

template <class T>
class Queue
{
private:
	struct node
	{
		T value;
		node *next;
	};
	node *_front;
	node *_back;
	int _size;
public:
	Queue();
	~Queue();
	void clear();
	void enqueue(T);
	T dequeue();
	bool isEmpty() const { return _size == 0; };
	int size() const { return _size; };

	class EmptyQueueException {};
};

template <class T>
Queue<T>::Queue()
{
	_front = nullptr;
	_back = nullptr;
	_size = 0;
}

template <class T>
Queue<T>::~Queue()
{
	clear();
}

template <class T>
void Queue<T>::clear()
{
	node *tmp = nullptr;
	node *current = _front;

	while (current != nullptr)
	{
		tmp = current->next;
		delete current;
		current = tmp;
	}
	_back = nullptr;
	_size = 0;
}

template <class T>
void Queue<T>::enqueue(T value)
{
	node *newNode = new node();
	newNode->value = value;

	if (_back == nullptr)
	{
		_front = newNode;
		_back = newNode;
	}
	else
	{
		_back->next = newNode;
		_back = _back->next;
	}

	_size += 1;
}

template <class T>
T Queue<T>::dequeue()
{
	if (isEmpty())
	{
		throw EmptyQueueException();
	}
	node *tmp = _front;
	T value = tmp->value;
	_front = tmp->next;
	delete tmp;
	_size -= 1;
	return value;
}

#endif
