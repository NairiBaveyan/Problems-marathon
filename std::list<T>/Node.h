#ifndef NODE_H_
#define NODE_H_

template <typename Type>
class Node
{
public:
	Node() = default;
	//Node(Type data);
	Node(Type data,Node<Type>* next = nullptr);

public:

	Type m_data{};
	Node<Type>* m_next{};

};


#endif //NODE_H_
