// Liskovskis_Ricards_221RDB484

#include <iostream>

using namespace std;

bool isPrime(int num)
{
  if (num <= 1)
  {
    return false;
  }

  // checking if number is divisible by any
  // number between 2 and the number itself (not included)
  int i = 2;
  while (i < num)
  {
    if (num % i == 0)
    {
      break;
    }
    i++;
  }

  // if number is not divisible by any other number other
  // than itself and 1, it is a prime
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