#include "MyQueue.h"

template <typename T>
bool MyQueue<T>::isEmpty()const
{
        return source.isEmpty;
}

template<typename T>
bool MyQueue<T>::enqueue(T param)
{
        bool result = false;
        if(count < MAX_QUEUE)
        {
                ++count;
                back = (back + 1) % MAX_QUEUE;
                result = source.push(param);
        }
        return result;
}


template<typename T>
bool MyQueue<T>::dequeue()
{
        bool result = false;
        if(!source.isEmpty())
        {
                front = (front +1)% MAX_QUEUE;
                --count;
                for(int i{};i<count-1;++i)
                {
                        tmp.push(source.peek());
                        source.pop();

                }
                source.pop();
                --count;
                for(int i{};i<count;++i)
                {
                        source.push(tmp.peek());
                        tmp.pop();
                }
                result = true;
        }
        return result;
}


template <typename T>
T MyQueue<T>::peekFront()
{
        return source.peek();
}
