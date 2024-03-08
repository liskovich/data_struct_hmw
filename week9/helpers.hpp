#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <string>

using namespace std;

bool is_operand(char);
int precedence(char);
string infix_to_postfix(string);

#endif
