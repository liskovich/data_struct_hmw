#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <string>

using namespace std;

// same as in week 9 HW
bool is_valid_input(string);
int precedence(char);
string infix_to_postfix(string);

// also move evaluate_postfix to lib
double evaluate_postfix(const string &postfix);

#endif
