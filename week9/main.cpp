#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
  string user_input;
  cin >> user_input;

  stack<int> numbers;
  stack<char> operators;

  string current_num = "";
  for (int i = 0; i < user_input.size(); i++)
  {
    if (user_input[i] == '+' || user_input[i] == '-' || user_input[i] == '*' || user_input[i] == '/' || user_input[i] == '(' || user_input[i] == ')')
    {
      if (current_num.size() != 0)
      {
        numbers.push(stoi(current_num));
      }

      current_num = "";
      if (user_input[i] != '(' && user_input[i] != ')')
      {
        operators.push(user_input[i]);
      }
    }
    else
    {
      current_num.push_back(user_input[i]);
    }
  }
  if (current_num.size() != 0)
  {
    numbers.push(stoi(current_num));
  }

  cout << "Numbers:" << endl;
  while (!numbers.empty())
  {
    cout << numbers.top() << " ";
    numbers.pop();
  }
  cout << endl;

  cout << "Operators:" << endl;
  while (!operators.empty())
  {
    cout << operators.top() << " ";
    operators.pop();
  }
  cout << endl;

  return 0;
}
