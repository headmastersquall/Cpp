#ifndef LINKNODE_H_
#define LINKNODE_H_

template <class T>
class LinkNode {
public:
	T value;
	LinkNode<T> *next;

	LinkNode(T newValue)
	{
		value = newValue;
		next = nullptr;
	}
};

#endif
