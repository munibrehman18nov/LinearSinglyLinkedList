#include<iostream>
using namespace std;
#include"LSLL.h"

int main()
{
	LSLL<int> l;
	LSLL<int> l1;
	LSLL<int> resultList;
	l.insertNodeInEnd(1);
	l.insertNodeInEnd(2);
	l.insertNodeInEnd(3);
	l.insertNodeInEnd(4);
	l.insertNodeInEnd(5);
	cout << "List#1: "; l.traverse();
	cout << endl;
	l1.insertNodeInEnd(11);
	l1.insertNodeInEnd(22);
	l1.insertNodeInEnd(33);
	l1.insertNodeInEnd(44);
	l1.insertNodeInEnd(55);
	cout << "List#2: "; l1.traverse();
	cout << endl;
	resultList.insertNodeInEnd(0);
	resultList.insertNodeInEnd(0);
	resultList.insertNodeInEnd(0);
	resultList.insertNodeInEnd(0);
	resultList.insertNodeInEnd(0);
/*	l.traverse();
	cout << endl << endl;*/
	LSLL<int>::LSLLIterator i = l;
	LSLL<int>::LSLLIterator j = l1;
	LSLL<int>::LSLLIterator r = resultList;
	while (!i.isDone())
	{
		*r = *i + *j;
		r.next();
		i.next();
		j.next();
	}
	r = resultList;
	//l.traverse();
	//cout << endl << endl;
	cout << "Resultant (Addition of 1st & 2nd) List: ";
	while (!r.isDone())
	{
		cout << *r << " ";
		r.next();
	}
	cout << endl;
/*	LSLL<int>l1(l);
//	cout << l.search(20) << '\n';
//	l.deleteNodeManually(40);
	l1.traverse();
	cout << endl << endl;
//	cout << l.search(40) << '\n';*/
}