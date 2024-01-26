// Liskovskis_Ricards_221RDB484

#include <iostream>

using namespace std;

int getCityYear(int p0, double perc, int delta, int p)
{
  perc = perc / 100;
  int growthRate = p0 * perc + delta;
  if (delta <= 0)
  {
    return -1;
  }

  int prevYear = p0;
  int yearNum = 0;
  while (prevYear < p)
  {
    int thisYear = prevYear + prevYear * perc + delta;
    yearNum++;
    cout << "Year " << yearNum << " population: " << thisYear << endl;
    prevYear = thisYear;
  }
  return yearNum;
}

int main()
{
  int p0 = 1000;
  double perc = 2;
  int delta = 50;
  int p = 1200;

  int years = getCityYear(p0, perc, delta, p);
  if (delta != -1)
  {
    cout << "Will reach the given population in " << years << " years" << endl;
  }
  else
  {
    cout << "Will never reach the given population" << endl;
  }
  return 0;
}