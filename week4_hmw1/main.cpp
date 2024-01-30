// Liskovskis_Ricards_221RDB484

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void trim(string &str);

int main()
{
  // create a stream for file reading
  string file_path = "missing_2_numbers.txt";
  ifstream input_file(file_path);

  // check if file can be opened
  if (!input_file.is_open())
  {
    cerr << "Error opening file: " << file_path << endl;
    return -1;
  }

  // init number array and set all elements to 0
  // to later check which are empty
  int read_nums[50] = {0};

  // read lines from file and store to array
  string line;
  while (getline(input_file, line))
  {
    trim(line);
    if (line != "")
    {
      // assign each number to their according index in array
      int num = stoi(line);
      read_nums[num - 1] = num;
    }
  }

  input_file.close();

  // show all numbers which have not been filled
  for (int i = 0; i < 50; i++)
  {
    if (read_nums[i] == 0)
    {
      cout << "Missing number: " << i + 1 << endl;
    }
  }
  return 0;
}

// trims a string by removing whitespace
// from both ends of a string (used ChatGPT for this function)
void trim(string &str)
{
  str.erase(str.begin(), find_if_not(str.begin(), str.end(), ::isspace));
  str.erase(find_if_not(str.rbegin(), str.rend(), ::isspace).base(), str.end());
}