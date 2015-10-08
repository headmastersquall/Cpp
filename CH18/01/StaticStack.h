#ifndef STATICSTACK_H_
#define STATICSTACK_H_

template <class T>
class StaticStack
{
private:
	T* _items;
	int _capacity;
	int _position;
	int _size;
public:
	StaticStack(int);
	~StaticStack();
	bool isEmpty() const;
	bool isFull() const;
	void push(T);
	T pop();
	void clear();
	int size() const { return _size; };

	class FullStackException {};
	class EmptyStackException {};
};

template <class T>
StaticStack<T>::StaticStack(int capacity)
{
	_items = new T[capacity];
	_capacity = capacity;
	_position = -1;
	_size = 0;
}

template <class T>
StaticStack<T>::~StaticStack()
{
	delete [] _items;
}

template <class T>
bool StaticStack<T>::isEmpty() const
{
	return _position == -1;
}

template <class T>
bool StaticStack<T>::isFull() const
{
	return _position == _capacity - 1;
}

template <class T>
void StaticStack<T>::push(T value)
{
	if (isFull())
	{
		throw FullStackException();
	}
	_size += 1;
	_items[++_position] = value;
}

template <class T>
T StaticStack<T>::pop()
{
	if (isEmpty())
	{
		throw EmptyStackException();
	}
	_size -= 1;
	return _items[_position--];
}

template <class T>
void StaticStack<T>::clear()
{
	_position = -1;
	_size = 0;
}

#endif
