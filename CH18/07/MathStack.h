#ifndef MATH_STACK_H
#define MATH_STACK_H

template <class T>
class MathStack
{
private:
	struct Node
	{
		T value;
		Node *next;
	};

	Node *_head;
	int _size;

public:
	MathStack();
	~MathStack();
	void push(T value);
	T pop();
	int size() const;
	bool isEmpty() const;
	void add();
	void sub();
	void mult();
	void div();
	void addAll();
	void multAll();
	class EmptyStackException {};
};

template <class T>
MathStack<T>::MathStack()
{
	_head = nullptr;
	_size = 0;
}

template <class T>
MathStack<T>::~MathStack()
{
	Node *current = _head;
	Node *tmp = nullptr;

	while (current != nullptr)
	{
		tmp = current;
		delete current;
		current = tmp->next;
	}
	_head = nullptr;
	_size = 0;
}

template <class T>
void MathStack<T>::push(T value)
{
	Node *newNode = new Node();
	newNode->value = value;

	if (_head == nullptr)
	{
		_head = newNode;
	}
	else
	{
		newNode->next = _head;
		_head = newNode;
	}
	_size += 1;
}

template <class T>
T MathStack<T>::pop()
{
	if (_size == 0)
	{
		throw EmptyStackException();
	}

	Node *tmp = nullptr;
	T value = _head->value;
	tmp = _head;
	_head = _head->next;
	delete tmp;
	_size -= 1;
	return value;
}

template <class T>
int MathStack<T>::size() const
{
	return _size;
}

template <class T>
bool MathStack<T>::isEmpty() const
{
	return _size == 0;
}

template <class T>
void MathStack<T>::add()
{
	push(pop() + pop());
}

template <class T>
void MathStack<T>::sub()
{
	T val1 = pop();
	T val2 = pop();
	push(val2 - val1);
}

template <class T>
void MathStack<T>::mult()
{
	push(pop() * pop());
}

template <class T>
void MathStack<T>::div()
{
	T val1 = pop();
	T val2 = pop();
	push(val2 / val1);
}

template <class T>
void MathStack<T>::addAll()
{
	T sum = pop();
	while (!isEmpty())
	{
		sum += pop();
	}
	push(sum);
}

template <class T>
void MathStack<T>::multAll()
{
	T prod = pop();
	while (!isEmpty())
	{
		prod *= pop();
	}
	push(prod);
}

#endif
