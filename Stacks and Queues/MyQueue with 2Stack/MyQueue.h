#ifndef MYQUEUE_H
#define MYQUEUE_H
#include "Stack.h"


int MAX_QUEUE = MAX_STACK;

template <typename T>
class MyQueue{
public:
	bool enqueue(T);
	bool dequeue();
	bool isEmpty()const;
	T peekFront();
	
private:
	int front{};
	int back {};
	int count{};
	Stack<T> source,tmp;
};


#endif //MYQUEUE_H



