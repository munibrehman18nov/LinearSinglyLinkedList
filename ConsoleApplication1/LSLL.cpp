#include<iostream>
using namespace std;
#include "LSLL.h"
#include"NotAllowed.h"

template<class T>
LSLL<T>::LSLL()
{
	start = nullptr;
	end = nullptr;
}
template<class T>
LSLL<T>::LSLL(LSLL<T>&s)
{
	cout << "Copy CTOR" << endl;
	Node<T>*t = s.start;
	Node<T>*c = 0;
	if (t != nullptr)
	{
		while (t->link != nullptr)
		{
			insertNodeInEnd(t->info);
			t = t->link;
		}
		insertNodeInEnd(t->info);
	}
}

template<class T>
LSLL<T>& LSLL<T>:: operator=(const LSLL<T>&s)
{
	cout << "Assignment Operator" << endl;
	Node<T>*t = s.start;
	Node<T>*c = 0;
	if (t != nullptr)
	{
		while (t->link != nullptr)
		{
			insertNodeInEnd(t->info);
			t = t->link;
		}
		insertNodeInEnd(t->info);
	}
	return *this;
}
template<class T>
Node<T>* LSLL<T>::createNode()
{
	Node<T>*n = new Node<T>;
	return n;
}
template<class T>
void LSLL<T>::insertNodeInBeg(T d)
{
	Node<T>*s = 0;
	Node<T>*temp = createNode();
	temp->info = d;
	temp->link = nullptr;
	if (start == nullptr)
	{
		start = temp;
		end = temp;
	}
	else
	{
		s = start;
		start = temp;
		temp->link = s;
	}
}
template<class T>
void LSLL<T>::insertNodeInEnd(T d)
{
	Node<T>*t = 0;
	Node<T>*temp = createNode();
	temp->info = d;
	temp->link = nullptr;
	if (start == nullptr)
	{
		start = temp;
		end = temp;
	}
	else
	{
		t = start;
		while (t->link != nullptr)
			t = t->link;
		t->link = temp;
		end = temp;
	}
}
template<class T>
void LSLL<T>::insertNodeManually(int pos, T d)
{
	Node<T>*s = 0;
	Node<T>*t = 0;
	int c = 0;
	Node<T>*temp = createNode();
	temp->info = d;
	temp->link = nullptr;
	if (pos == 1)
	{
		insertNodeInBeg(d);
	}
	else
	{
		s = start;
		while (s->link != nullptr)
		{
			s = s->link;
			c = c + 1;
		}
		c = c + 1;
		try
		{
			if (pos <= 0 || pos > c)
			{
				throw(NotAllowed("Invalid Position\n"));
			}
				s = start;
				for (int i = 1; i < pos; i++)
				{
					t = s;
					s = s->link;
				}
				t->link = temp;
				temp->link = s;
		}
		catch (NotAllowed&n)
		{
			n.printMsg();
		}
	}
}
template<class T>
void LSLL<T>::deleteNodeFromBeg()
{
	Node<T>*r;
	try
	{
		if (start == nullptr)
		{
			throw(NotAllowed("list is Empty.\n"));
		}
			r = start;
			start = start->link;
			delete r;
			r = nullptr;
	}
	catch (NotAllowed&n)
	{
		n.printMsg();
	}
}
template<class T>
void LSLL<T>::deleteNodeFromEnd()
{
	Node<T>*r; Node<T>*s = 0;
	try
	{
		if (start == nullptr)
		{
			throw(NotAllowed("list is Empty.\n"));
		}
			r = start;
			while (r->link != nullptr)
			{
				s = r;
				r = r->link;
			}
			free(r);
			s->link = nullptr;
	}
	catch (NotAllowed&n)
	{
		n.printMsg();
	}
}
template<class T>
void LSLL<T>::deleteNodeManually(T pos)
{
	if (pos == 1)
		deleteNodeFromBeg();
	else
	{
		Node<T>*r = 0, *s = 0;
		int c = 0;
		try
		{
			if (start == nullptr)
			{
				throw(NotAllowed("list is Empty.\n"));
			}
			s = start;
			while (s->link != nullptr)
			{
				s = s->link;
				c = c + 1;
			}
			c = c + 1;
			if (c == pos)
				deleteNodeFromEnd();
			else
			try
			{
				if (pos <= 0 || pos > c)
				{
					throw(NotAllowed("Invalid Position\n"));
				}
				r = start;
				for (int i = 1; i < pos; i++)
				{
					s = r;
					r = r->link;
				}
				s->link = r->link;
				free(r);
			}
			catch (NotAllowed&n)
			{
				n.printMsg();
			}
		}
		catch (NotAllowed&n)
		{
			n.printMsg();
		}
	}
}
template<class T>
Node<T>*LSLL<T>::search(T val)
{
	Node<T>*s = 0;
	s = start;
	try
	{
		while (s->info != val)
		{
			if (s->link == nullptr)
			{
				throw(NotAllowed("Value Not Found\n"));
			}
			s = s->link;
		}
		return s->link;
	}
	catch (NotAllowed&n)
	{
		n.printMsg();
	}
	return (Node<T>*)0;
}

template<class T>
void LSLL<T>::traverse()
{
	Node<T>*t;
	try
	{
		if (start == nullptr)
			throw(NotAllowed("List is Empty.\n"));
		t = start;
		while (t != nullptr)
		{
			cout << t->info << "  ";
			t = t->link;
		}
	}
	catch (NotAllowed&n)
	{
		n.printMsg();
	}
}
template<class T>
LSLL<T>::~LSLL()
{
	delete start;
	start = nullptr;
}
template<class T>
LSLL<T>::LSLLIterator::LSLLIterator()
{
	list = 0;
	current = nullptr;
}
template<class T>
LSLL<T>::LSLLIterator::~LSLLIterator()
{

}
template<class T>
LSLL<T>::LSLLIterator::LSLLIterator(LSLL<T>&l)
{
	list = &l;
	current = l.start;
}
template<class T>
T& LSLL<T>::LSLLIterator::operator*()
{
	try
	{
		if (current != nullptr)
			return current->info;
		throw(NotAllowed("Invalid Access. Try Again\n"));
	}
	catch (NotAllowed &n)
	{
		n.printMsg();
	}
}
template<class T>
void LSLL<T>::LSLLIterator::start()
{
	try
	{
		if (list == nullptr)
		{
			throw(NotAllowed("Invlalid Access\n"));
		}
		current = list->start;
	}
	catch (NotAllowed&n)
	{
		n.printMsg();
	}

}
template<class T>
bool LSLL<T>::LSLLIterator::isDone()
{
	if (current == nullptr)
		return true;
	return false;
}
template<class T>
void LSLL<T>::LSLLIterator::next()
{
	if (current != nullptr)
		current = current->link;
}




template LSLL<int>;