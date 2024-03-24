#include "helpers.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

string read_file(string filename)
{
  ifstream file(filename);
  string content;
  char c;

  if (file.is_open())
  {
    while (file.get(c))
    {
      // Check if character is not whitespace
      if (!isspace(c))
      {
        content.push_back(c);
      }
    }
  }
  else
  {
    cout << "Error: Could not open file: " << filename << endl;
  }
  return content;
}

int main()
{
  string user_input;

  // cin >> user_input;
  // read arithmetic expression from file
  string filename = "sequence_with_parenthesis.txt";
  user_input = read_file(filename);

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
