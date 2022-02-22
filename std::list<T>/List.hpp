#include <utility>
#include "List.h"

template <typename T>
void NSTL::print(T data)
{
	std::cout<<data<<std::endl;
}

/*template <typename T>
void NSTL::List<T>::change(T data)
{
	m_data = data;
}*/


template <typename T>
bool NSTL::List<T>::isEmpty()const
{
	return m_size > 0 ?false:true;
}


template <typename T>
void NSTL::List<T>::push_back(T data)
{
	if(!m_head){
		m_head->m_next = new Node<T>(data);
	}else{
		Node<T>* cur = m_head;
		while(cur->m_next!=nullptr)
		{
			cur =cur->m_next; 
		}
		cur->m_next = new Node<T>(data);

	}
	++m_size;	
}

template <typename T>
void NSTL::List<T>::push_front(T data)
{
	if(isEmpty()){
		m_head = new Node<T>(data);
	}else{
		Node<T>*tmp = new Node<T>(data,m_head);
		m_head = tmp;
		tmp = nullptr;
	}
	++m_size;

}


template <typename T>
void NSTL::List<T>::pop_front()
{
	if(isEmpty()){
		return ;
	}else{
		Node<T>* cur = m_head->m_next;
		delete m_head;
		m_head = cur;
		cur = nullptr;
	}
}


template <typename T>
T& NSTL::List<T>::front()const
{
	return m_head->m_data;
}

template <typename T>
void NSTL::List<T>::insert(T data,size_t pos)
{
	if(pos > m_size){
		return ;
	}
	Node<T>* prev = m_head;
	for(int i{};i < pos-1;++i)
	{
		prev = prev->m_next;
	}
	Node<T>* newNode = new Node<T>(data,prev->m_next);
	prev->m_next = newNode;
	++m_size;
}

template <typename T>
void NSTL::List<T>::clear()
{
	while(m_size)
	{
		this->pop_front();
		--m_size;
	}
}


template <typename T>
void NSTL::List<T>::remove_at(size_t pos)
{
	if(pos > m_size)
		return ;
	Node<T>* tmp = this->m_head;
	for(int i{};i < pos;++i)
	{
		tmp = tmp->m_next;
	}
	Node<T>* del = tmp->next;
	tmp = del->m_next;
	delete del;
	--m_size;
}


template <typename T>
void NSTL::List<T>::traverse(void(*ptr_print)(T))
{
	Node<T>* cur = m_head;
	while(cur)
	{
		ptr_print(cur->m_data);
		cur = cur->m_next;
	}
}


template <typename T>
NSTL::List<T>::~List()
{
	this->clear();
}


template <typename T>
NSTL::List<T>::List(size_t count)
{
	for(int i{};i < count;++i)
	{
		this->push_front(0);
		++m_size;
	}
}


template <typename T>
NSTL::List<T>::List(size_t count,T& data)
{
	for(int i{};i < count;++i)
	{
		this->push_front(data);
		++m_size;
	}
}


template <typename T>
NSTL::List<T>::List(const List<T>& rhs)
{
	Node<T>* tmp = rhs.m_head;
	for(int i{};i < rhs.m_size;++i)
	{
		this->push_front(tmp->m_data);
		tmp = tmp->m_next;
	}
}


template <typename T>
NSTL::List<T>& NSTL::List<T>::operator=(const List<T>& rhs)
{
	if(this == &rhs)
	{
		return *this;
	}
	this->clear();
	Node<T>* tmp = rhs.m_head;
	size_t p = 0;
	while(tmp)
	{
		this->insert(tmp->m_data,p);
		++p;
		tmp=tmp->m_next;
	}
	return *this;
}

template <typename T>
NSTL::List<T>& NSTL::List<T>::operator=(List<T>&& rhs)noexcept
{
	if(this == &rhs)
		return *this;
	this->clear();
	this->m_head = rhs.m_head;
	this->m_size = rhs.m_size;
	rhs.m_head = nullptr;
	rhs.m_size = 0;
	return *this;
}

template <typename T>
NSTL::List<T>::List(List<T>&& rhs)noexcept
	:m_head{std::exchange(rhs.m_head,nullptr)},
	 m_size{std::exchange(rhs.m_size,0)}
{}




