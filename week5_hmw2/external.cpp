#include <iostream>
#include "external.hpp"

using namespace std;

Song::Song(string title = "", string author = "", string lyrics = "", int year = 0)
    : title(title), author(author), lyrics(lyrics), year(year)
{
  cout << "New Song made - " << author << " - " << title << endl;
}

Song &Song::sing(int max_lines = -1)
{
  cout << title << " - " << author << " - " << year << endl;
  int lines = 0;

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
        cout << endl;
      }
    }
    else
    {
      cout << lyrics[i];
    }
  }
  cout << endl;

  return *this;
}

Song &Song::yell(int max_lines = -1)
{
  cout << title << " - " << author << " - " << year << endl;
  int lines = 0;

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
        cout << endl;
      }
    }
    else
    {
      cout << (char)toupper(lyrics[i]);
    }
  }
  cout << endl;

  return *this;
}