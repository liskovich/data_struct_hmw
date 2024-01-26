// Liskovskis_Ricards_221RDB484

#include <iostream>

using namespace std;

int getCityYear(int p0, double perc, int delta, int p)
{
  if (perc <= 0 && p0 < p)
  {
    return -1;
  }

  perc = perc / 100;

  int prevYear = p0;
  int yearNum = 0;
  while (prevYear < p)
  {
    int thisYear = prevYear + prevYear * perc + delta;
    yearNum++;

    if (delta <= 0 && thisYear + delta <= p)
    {
      return -1;
    }

    cout << "Year " << yearNum << " population: " << thisYear << endl;
    prevYear = thisYear;
  }
  return yearNum;
}

int main()
{
  // case 1
  int p0 = 1500000;
  double perc = 2.5;
  int delta = 10000;
  int p = 2000000;

  // // case 2
  // int p0 = 1000;
  // double perc = -3;
  // int delta = 50;
  // int p = 2000;

  int years = getCityYear(p0, perc, delta, p);
  if (years != -1)
  {
    cout << "Will reach the given population in " << years << " years" << endl;
  }
  else
  {
    cout << "Will never reach the given population" << endl;
  }
  return 0;
}