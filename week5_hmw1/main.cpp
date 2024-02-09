#include <iostream>

using namespace std;

class Song
{
protected:
  string title;
  string author;
  string lyrics;
  int year;

public:
  Song(string, string, string, int);

  Song &sing(int);
  Song &yell(int);
};

// constructor
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
    // if newline encoutnered, check that
    // we need to continue printing lyrics
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

  // for chaining purposes
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
      // make a letter to uppercase
      cout << (char)toupper(lyrics[i]);
    }
  }
  cout << endl;

  // for chaining purposes
  return *this;
}

int main()
{
  Song barbie_girl("Barbie Girl", "Aqua", "I'm a Barbie girl, in the Barbie world\nLife in plastic, it's fantastic\nYou can brush my hair, undress me everywhere\nImagination, life is your creation", 1997);
  barbie_girl.sing(1).yell();
  return 0;
}
