#include <cstdio>
#include "Singleton.h"

int main() 
{
	auto& object1 = Singleton::getInstance();
	auto& object2 = Singleton::getInstance();
	printf("Object1 == Object2: %s", (&object1 == &object2) ? "True" : "False");
}