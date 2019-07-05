#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
public:
	T info;
	Node*link;
	Node();
	Node(T info);
	~Node();
};

#endif