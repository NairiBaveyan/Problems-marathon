#include <iostream>
#include "List.hpp"

int main()
{
	NSTL::List<int> obj;
	for(int i{1};i < 10;++i)
	obj.push_front(10*i);
	std::cout<<obj.front()<<std::endl;

	void (*pf)(int) = NSTL::print;
	obj.traverse(pf);
	std::cout<<std::endl;
	obj.clear();
	obj.push_front(10);
	std::cout<<obj.front()<<std::endl;
	
}
