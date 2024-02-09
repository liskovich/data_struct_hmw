#ifndef EXTERNAL_HPP
#define EXTERNAL_HPP

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

#endif
