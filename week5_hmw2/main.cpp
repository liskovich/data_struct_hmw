#include <iostream>
#include "external.hpp"

using namespace std;

class Rap : public Song
{
public:
  Rap(string, string, string, int);

  Rap &break_it(int, string);
};

// constructor
Rap::Rap(string title = "", string author = "", string lyrics = "", int year = 0)
    : Song(title, author, lyrics, year) {}

Rap &Rap::break_it(int max_lines = -1, string drop = "yeah")
{
  cout << title << " - " << author << " - " << year << endl;
  int lines = 0;

  // convert the drop to uppercase
  for (char &c : drop)
  {
    c = toupper(c);
  }

  for (int i = 0; i < lyrics.size(); i++)
  {
    if (lyrics[i] == '\n')
    {
      lines++;
      if (lines == max_lines)
      {
        break;
      }
      else
      {
        cout << " " << drop << " " << endl;
      }
    }
    else if (lyrics[i] == ' ')
    {
      cout << " " << drop << " ";
    }
    else
    {
      cout << lyrics[i];
    }
  }
  cout << " " << drop << endl;

  // for chaining purposes
  return *this;
}

int main()
{
  Rap barbie_girl("Barbie Girl", "Aqua", "I'm a Barbie girl, in the Barbie world\nLife in plastic, it's fantastic\nYou can brush my hair, undress me everywhere\nImagination, life is your creation", 1997);
  barbie_girl.break_it(2, "yo");
  return 0;
}
