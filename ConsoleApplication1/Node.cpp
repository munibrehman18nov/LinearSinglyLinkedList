#include "Node.h"

template<class T>
Node<T>::Node()
{
	info = 0;
}
template<class T>
Node<T>::Node(T val)
{
	info = val;
}
template<class T>
Node<T>::~Node()
{
}
template Node<int>;