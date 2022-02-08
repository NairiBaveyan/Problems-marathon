#ifndef LIST_H_
#define LIST_H_

//#include <iostream>
#include "Node.hpp"

namespace NSTL{
	
	template <typename T>
	void print();

	template <typename T>
	class List{
	public:
		List() = default;
		List(size_t count);
		List(size_t count,T& data); //count of data copys
		List(const List& rhs);
		List& operator=(const List& rhs);
		List(List&& rhs)noexcept;
		List& operator=(List&& rhs)noexcept;
		~List();

	public:
		bool isEmpty()const;
		void push_front(T data);
		void pop_front();
		T& front()const;
		void insert(T data,size_t pos);
		void emplace(T data,size_t pos);
		void erase(size_t pos);
		void clear();
		void remove_at(size_t pos);
		void reverse();
		void sort();
		void merge();//was't void
		void traverse(void(*ptr)(T));
		
	private:
		Node<T>* m_head{};
		size_t m_size{};
	private:
		void push_back(T data);
		void change(T data);
	};
}

#endif //LIST_H_


