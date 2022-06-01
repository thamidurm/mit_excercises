#include "StaticStack.h"
#include "DynamicStack.h"
#include <iostream>
int main() 
{

	DynamicStack<int> stack;
	stack.push(5);
	for(int i = 0; i < 20; ++i)
	stack.push(10);
	stack.push(5);
	//stack.push(5);
	stack.print();
	std::cout << stack.top() << std::endl;
	//std::cout << stack.pop() << std::endl;
	std::cout << "Capacity: " << stack.getCapacity() << std::endl; 
	std::cout << "Size: " << stack.getSize() << std::endl; 

}