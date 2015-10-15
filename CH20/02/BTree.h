#ifndef _BTREE_H
#define _BTREE_H

template <class T>
class BTree
{
private:
	struct Node
	{
		Node *left;
		T value;
		Node *right;
	};
	Node *root;
	void addNode(Node *&n, T value);
	void removeTree(Node *&n);
	Node* findNode(Node *n, T value) const;
	int nodeCount(Node *n, int &counter) const;
	void do_foreach(Node *n, void (*f)(T)) const;
public:
	BTree();
	~BTree();
	void add(T value) { addNode(root, value); };
	void clear() { removeTree(root); };
	bool hasValue(T value) const
	{
		return findNode(root, value) != nullptr;
	};
	T find(T) const;
	int count() const
	{
		int ct = 0;
		return nodeCount(root, ct);
	};
	void foreach(void (*f)(T)) const { do_foreach(root, f); };
	class ItemNotFoundException {};
};

template <class T>
BTree<T>::BTree()
{
	root = nullptr;
}

template <class T>
BTree<T>::~BTree()
{
	clear();
}

template <class T>
void BTree<T>::addNode(Node *&n, T value)
{
	if (n)
	{
		if (value < n->value)
		{
			addNode(n->left, value);
		}
		else
		{
			addNode(n->right, value);
		}
	}
	else
	{
		n = new Node();
		n->left = nullptr;
		n->right = nullptr;
		n->value = value;
	}
}

template <class T>
void BTree<T>::removeTree(Node *&n)
{
	if (n == nullptr)
	{
		return;
	}

	if (n->left)
		removeTree(n->left);
	if (n->right)
		removeTree(n->right);
	n->left = nullptr;
	n->right = nullptr;
	n = nullptr;
}

template <class T>
typename BTree<T>::Node* BTree<T>::findNode(Node *n, T value) const
{
	if (n == nullptr)
	{
		return nullptr;
	}

	if (n->value == value)
	{
		return n;
	}
	else if (value < n->value)
	{
		return findNode(n->left, value);
	}
	else
	{
		return findNode(n->right, value);
	}
}

template <class T>
T BTree<T>::find(T value) const
{
	Node *n = findNode(root, value);
	if (n == nullptr)
		throw BTree<T>::ItemNotFoundException();
	else
		return n->value;
}

template <class T>
int BTree<T>::nodeCount(Node *n, int &counter) const
{
	if (n == nullptr)
	{
		return counter;
	}
	counter += 1;
	nodeCount(n->left, counter);
	nodeCount(n->right, counter);
	return counter;
}

template <class T>
void BTree<T>::do_foreach(Node *n, void (*f) (T value)) const
{
	if (n == nullptr)
	{
		return;
	}
	do_foreach(n->left, f);
	f(n->value);
	do_foreach(n->right, f);
}

#endif
