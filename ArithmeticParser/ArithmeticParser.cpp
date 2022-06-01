
/*
Grammar for Arithmetic Expressions ( Unary +/- not included)
Expr -> (Expr) | Expr op Expr
Op -> + | - | * | /
Expr -> Num
*/



#include "pch.h"

using namespace ctpg;
using namespace ctpg::buffers;

int to_int(std::string_view sv)
{
    int i = 0;
    std::from_chars(sv.data(), sv.data() + sv.size(), i);
    return i;
}

constexpr nterm<int> expr("expr");

constexpr char number_pattern[] = "[0-9][0-9]*";
constexpr regex_term<number_pattern> number("number");

constexpr char_term o_plus('+', 1);
constexpr char_term o_minus('-', 1);
constexpr char_term o_mul('*', 2);
constexpr char_term o_div('/', 2);

constexpr parser p(
	expr,
	terms(o_plus, o_minus, o_div, o_mul, '(', ')', number),
	nterms(expr),
	rules(
        expr('(', expr, ')') >= [](char, int value, char)
        {
            return value;
        },
        expr(expr, '+', expr) >= [](int value1, char, int value2)
        {
	        return value1 + value2;
        },
        expr(expr, '-', expr) >= [](int value1, char, int value2)
        {
            return value1 - value2;
        },
        expr(expr, '/', expr) >= [](int value1, char, int value2)
        {
            return value1 / value2;
        },
        expr(expr, '*', expr) >= [](int value1, char, int value2)
        {
            return value1 * value2;
        },
		expr(number) >= to_int
	)
);

constexpr size_t BufLen = 512;
int main()
{
    char expression[BufLen];
    std::cin.getline(expression, BufLen);
    auto result = p.parse(string_buffer(expression), std::cerr);
    bool valid = result.has_value();
    if (valid)
        std::cout << expression << " = " << result.value() << std::endl;
    return valid ? 0 : -1;
}