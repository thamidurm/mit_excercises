
/*
Grammar for Arithmetic Expressions ( Unary +/- not included)
Expr -> (Expr) | Expr op Expr
Op -> + | - | * | /
Expr -> Num
*/

#include <iostream>

#include "Exception.h"
#include "Lexer.h"
#include "Parser.h"

constexpr size_t BufSize = 512u;
int main()
{
	Lexer lexer;
	Parser parser;
	// Unary operators need to be within brackets
	try
	{
		char buffer[BufSize];
		std::cout << "Enter expression: ";
		std::cin.getline(buffer, BufSize);
		auto tokens = lexer.tokenize(buffer);
		auto result = parser.parse(tokens);
		std::cout << "Answer is: " << result;
	}
	catch (Exception& e)
	{
		std::cerr << e.getMessage() << std::endl;
		return 1;
	}
}