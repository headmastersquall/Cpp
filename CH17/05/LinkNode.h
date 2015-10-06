#ifndef LINKNODE_H_
#define LINKNODE_H_

class LinkNode {
public:
	int value;
	LinkNode *next;

	LinkNode(int newValue)
	{
		value = newValue;
		next = nullptr;
	}
};

#endif
