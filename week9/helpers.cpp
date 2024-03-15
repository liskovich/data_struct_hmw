#include "helpers.hpp"

#include <stack>
#include <string>

bool is_operator(char c)
{
  return c == '+' || c == '-' || c == '*' || c == '/';
}

// check that user wrote valid expression
bool is_valid_input(string user_input)
{
  int open_bracket_count = 0;
  int close_bracket_count = 0;
  int operator_count = 0;
  int number_count = 0;

  string current_num = "";

  for (auto c : user_input)
  {
    if (isdigit(c))
    {
      current_num += c;
    }
    else if (is_operator(c))
    {
      operator_count++;
      if (current_num != "")
      {
        number_count++;
        current_num = "";
      }
    }
    else if (c == '(')
    {
      open_bracket_count++;
      if (current_num != "")
      {
        number_count++;
        current_num = "";
      }
    }
    else if (c == ')')
    {
      close_bracket_count++;
      if (current_num != "")
      {
        number_count++;
        current_num = "";
      }
    }
    else
    {
      return false;
    }
  }

  if (current_num != "")
  {
    number_count++;
  }
  if (operator_count + 1 != number_count)
  {
    return false;
  }
  if (open_bracket_count != close_bracket_count)
  {
    return false;
  }

  return true;
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