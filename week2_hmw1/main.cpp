// Liskovskis_Ricards_221RDB484

#include <iostream>

using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;

  if (a > b) {
    int temp = a;
    a = b;
    b = temp;
  }
  if (b > c) {
    int temp = b;
    b = c;
    c = temp;
  }
  if (a > b) {
    int temp = a;
    a = b;
    b = temp;
  }
  cout << "Number 1: " << a << endl << "Number 2: " << b << endl << "Number 3: " << c << endl;  

  return 0;
}