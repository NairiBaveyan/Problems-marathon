#ifndef STACK_H
#define STACK_H

const int MAX_STACK = 100;

template <class Type>
class StackInterface{
public:
	virtual bool isEmpty()const = 0;
	virtual bool push(Type) = 0;;
	virtual bool pop() = 0;
	virtual Type peek()const = 0;
};



template <class Type>
class Stack:public StackInterface <Type>{
public:
	Stack();
	Stack(Type);
	Stack(const Stack& rhs);
	Stack& operator = (const Stack& rhs);
	Stack(Stack&& rhs)noexcept;
	Stack& operator = (Stack&& rhs)noexcept;
	~Stack();
public:
	virtual bool isEmpty()const ;
	virtual bool push(Type) ;
	virtual bool pop() ;
	virtual Type peek()const; 
	Type getMin()const;
private:
	int top;
	Type* arr ;
	Type min;
};






#endif //STACK_H
