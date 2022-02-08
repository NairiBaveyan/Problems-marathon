#include <iostream>
#include "List.hpp"

int main()
{
	NSTL::List<int> obj;
	for(int i{1};i < 10;++i)
		obj.push_front(10*i);
	std::cout<<obj.front()<<std::endl;

	NSTL::List<int> obj2(obj);
	void (*pf)(int) = NSTL::print;
	obj2.traverse(pf);
	std::cout<<std::endl;
}
