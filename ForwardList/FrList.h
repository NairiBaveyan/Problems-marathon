#ifndef	FR_LIST_H_ 
#define FR_LIST_H_


template <typename T>
class FrList{
public:
	FrList() = default;
	FrList(T);
	FrList(const FrList& rhs);
	FrList& operator = (const FrList& rhs);
	FrList(FrList&& rhs)noexcept;
	FrList& operator = (FrList&& rhs)noexcept;
	~FrList();

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

private:
	FrNode<T>* m_head{};
	FrNode<T>* m_tail{};
	FrNode<T>* m_shead{};
	FrNode<T>* m_ghead{};
	size_t m_size;
	void _put_sorted(FrNode<T>*& n);

};

#endif
_put_sorted(FrNode<T>*& n)

insert
1 push front
2 push back
3 insert

access


