#include "Node.h"

/*template <typename Type>
Node<T>::Node(Type data)
	:m_data{data}
{}
*/
template <typename Type>
Node<Type>::Node(Type data,Node<Type>* next)
	:m_data{data},m_next{next}
{}
/*
template <typename Type>
void Node<Type>::setVal(const Type& data)
{
	m_data = data;
}

template <typename Type>
void Node<Type>::setNext(const Node<Type>* next)
{
	m_next = next;
}


template <typename Type> 
Type& Node<Type>::getVal()const
{
	return m_data;
}

template <typename Type>
Node<Type>* Node<Type>::getNext()const
{
	return m_next;
}
*/
