#include "helpers.hpp"

#include <stack>
#include <string>

bool is_operand(char c)
{
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// determine precedence of operators
int precedence(char c)
{
  switch (c)
  {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  default:
    return -1;
  }
}

// convert standard arithmetic expression (infix)
// form to postfix using shunting yard algorithm
string infix_to_postfix(string infix)
{
  stack<char> s;
  string postfix;
  string current_num;

  for (int i = 0; i < infix.size(); i++)
  {
    char c = infix[i];

    // accumulate all digits of the current number
    if (isdigit(c))
    {
      current_num += c;
    }
    else
    {
      if (!current_num.empty())
      {
        postfix += current_num;
        // add space to distinguish separate numbers and operators
        postfix += ' ';
        current_num = "";
      }

      // handle expressions inside brackets
      if (c == '(')
      {
        s.push(c);
      }
      else if (c == ')')
      {
        // pop from the stack until '(' is found
        while (!s.empty() && s.top() != '(')
        {
          postfix += s.top();
          postfix += ' ';
          s.pop();
        }
        s.pop();
      }
      else
      {
        // pop higher or equal precedence operators
        while (!s.empty() && precedence(c) <= precedence(s.top()))
        {
          postfix += s.top();
          postfix += ' ';
          s.pop();
        }
        s.push(c);
      }
    }
  }

  // handle the last number
  if (!current_num.empty())
  {
    postfix += current_num;
    postfix += ' ';
  }

  // pop remaining operators from the stack
  while (!s.empty())
  {
    postfix += s.top();
    postfix += ' ';
    s.pop();
  }

  return postfix;
}