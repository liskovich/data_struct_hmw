#include <iostream>

using namespace std;

void collatz(int num, int &steps)
{
  cout << "Step #" << steps << ": " << num << endl;

  // exit condition
  if (num == 1)
  {
    return;
  }

  steps++;
  // collatz checking
  if (num % 2 == 0)
  {
    collatz(num / 2, steps);
  }
  else
  {
    collatz(num * 3 + 1, steps);
  }
}

int main()
{
  int number;
  cin >> number;

  int steps = 0;
  collatz(number, steps);
  cout << "Total steps: " << steps << endl;
  return 0;
}
