#include <iostream>

using namespace std;

bool isPrime(int num)
{
  if (num <= 1)
  {
    return false;
  }

  int i = 2;
  while (i < num)
  {
    if (num % i == 0)
    {
      break;
    }
    i++;
  }

  if (i == num)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  int num;
  cout << "Enter a number to check for prime:" << endl;
  cin >> num;
  string primeCheck = isPrime(num) ? "true" : "false";
  cout << "is prime?: " << primeCheck << endl;
  return 0;
}