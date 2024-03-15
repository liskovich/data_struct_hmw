#include "helpers.hpp"

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

#include <algorithm>
#include <cctype>
#include <locale>

using namespace std;

double evaluate_postfix(const string &postfix)
{
  stack<double> st;
  istringstream iss(postfix);
  string token;
  while (iss >> token)
  {
    // determine whether it is number or operator
    if (isdigit(token[0]))
    {
      st.push(stod(token));
    }
    else
    {
      // get operands to calculate on
      double operand2 = st.top();
      st.pop();
      double operand1 = st.top();
      st.pop();

      // perform operation
      switch (token[0])
      {
      case '+':
        st.push(operand1 + operand2);
        break;
      case '-':
        st.push(operand1 - operand2);
        break;
      case '*':
        st.push(operand1 * operand2);
        break;
      case '/':
        st.push(operand1 / operand2);
        break;
      default:
        cout << "error: Invalid operator: " << token << endl;
        return 0;
      }
    }
  }
  if (st.size() == 1)
  {
    return st.top();
  }
  else
  {
    cout << "error: Invalid postfix expression" << endl;
    return 0;
  }
}

int main()
{
  string user_input;
  cin >> user_input;

  if (!is_valid_input(user_input))
  {
    cout << "error" << endl;
    return -1;
  }

  string postfix = infix_to_postfix(user_input);
  cout << "Postfix expression: " << postfix << endl;

  double res = evaluate_postfix(postfix);
  if (res == -1.0)
  {
    cout << "error" << endl;
  }
  else
  {
    cout << "Result: " << res << endl;
  }

  return 0;
}
