#include "StaticStack.h"
#include "DynamicStackLL.h"
#include "DynamicStack.h"
#include <iostream>

int& g() {
	return 1;
}

int main() 
{
	const int const * const x = nullptr;
	int x = g();
	x = 5;
	DynamicStack<int> stack;
	stack.push(5);
	for(int i = 0; i < 20; ++i)
	stack.push(10);
	stack.push(5);
	stack.push(5);
	stack.print();
	//std::cout << stack.top() << std::endl;
	//std::cout << stack.pop() << std::endl;
	//std::cout << "Capacity: " << stack.getCapacity() << std::endl; 
	std::cout << "Size: " << stack.getSize() << std::endl; 

}