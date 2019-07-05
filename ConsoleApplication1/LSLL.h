#ifndef SLL_H
#define SLL_H
#include"Node.h"

template<class T>
class LSLL
{
	Node<T>*start;
	Node<T>*end;
public:
	class LSLLIterator
	{
		LSLL<T>*list;
		Node<T>*current;
	public:
		LSLLIterator();
		~LSLLIterator();
		LSLLIterator(LSLL<T>&);
		T & operator*();
		void start();
		bool isDone();
		void next();
	};
	LSLL<T>();
	Node<T>*createNode();
	LSLL<T>(LSLL<T>&);
	LSLL<T>& operator=(const LSLL<T>&);
	void insertNodeInBeg(T=0);
	void insertNodeInEnd(T=0);
	void insertNodeManually(int pos, T=0);
	void deleteNodeFromBeg();
	void deleteNodeFromEnd();
	void deleteNodeManually(T pos);
	Node<T>*search(T val);
	void traverse();
	~LSLL();
};

#endif