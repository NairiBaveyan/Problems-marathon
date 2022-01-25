#include "Stack.h"

template <class Type>
Stack<Type>::Stack()
	:top{-1}
{
	this ->arr = new Type[MAX_STACK];
}

template <class Type>
Stack<Type>::Stack(Type param)
	:top{-1}
{
	this ->arr = new Type[MAX_STACK];
	push(param);
	min = param;
}


template <class Type>
Stack<Type>::Stack(const Stack& rhs)
	:top{rhs.top},min{rhs.min}
{
	arr = new Type[MAX_STACK];
	for(int i{};i<=top;++i)
	{
		this->arr[i] = rhs.arr[i];
	}


}

template <class Type>
Stack<Type>& Stack<Type>::operator = (const Stack& rhs)
{
	if(this == &rhs)
		return *this;
	 //don't need to new declaretion off arr
	 //All Stacks have default MAX_SIZE
	this->top = rhs.top;
	min = rhs.min;
	for(int i{};i <= top;++i)
	{
		this ->arr[i] = rhs.arr[i];
	}
	return *this;
}

template <class Type>
Stack<Type>& Stack<Type>::operator=(Stack&& rhs)noexcept
{	min = rhs.min;
	top = rhs.top;
	arr = rhs.arr;
	rhs.top = rhs.min = 0;
	rhs.arr = nullptr;
	return *this;
}

template <class Type>
Stack<Type>::Stack(Stack&& rhs)noexcept
{
	min = rhs.min;
	arr = rhs.arr;
	top = rhs.top;
	rhs.arr = nullptr;
	rhs.top = rhs.min = 0;
}

template<class Type>
Stack<Type>::~Stack()
{
	delete[] arr;
}


template <class Type>
bool Stack<Type>::isEmpthy()const
{
	return top < 0;
}


template <class Type>
bool Stack<Type>::push(Type newItem)
{
	bool change = false;
	if(top < MAX_STACK - 1 ){
		++top;
		arr[top] = newItem;
		if(min > newItem){
			min = newItem;
		}
		change = true;
	}
	return change;
}


template <class Type>
bool Stack<Type>::pop()
{
	bool change = false;
	if(!isEmpthy()){
		--top;
		for(int i{};i<top;++i)
		{
			if(arr[i] < min)
				min = arr[i];
		}
		change = true;
	}
	return change;

}

template<class Type>
Type Stack<Type>::peek()const
{
	if(!isEmpthy())
		return arr[top];
	return -1;
}


template <class Type>
Type Stack<Type>::getMin()const
{
	if(!isEmpthy())
		return min;
	return -1;
}
