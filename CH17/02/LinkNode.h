#ifndef LINKNODE_H_
#define LINKNODE_H_

class LinkNode {
public:
	int nodeValue;
	LinkNode *next;

	LinkNode(int value)
	{
		nodeValue = value;
		next = nullptr;
	}
};

#endif
