#include <cstdio>

void printStackGrowthDirection(int* first) 
{
	int second = 2;

	if (&second > first) 
	{
		puts("Stack is growing up");
	}
	else 
	{
		puts("Stack is growing down");
	}
}

int main() 
{
	int first = 1;
	printStackGrowthDirection(&first);
}