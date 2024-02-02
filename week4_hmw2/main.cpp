// Liskovskis_Ricards_221RDB484

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void trim(string &str);
void bubble_sort(int arr[], int size);

int main()
{
  // create a stream for file reading
  string file_path = "numbers_-50_50_20.txt";
  ifstream input_file(file_path);

  // check if file can be opened
  if (!input_file.is_open())
  {
    cerr << "Error opening file: " << file_path << endl;
    return -1;
  }

  // get number of lines in file
  int line_count = 1;
  char current_char;
  while (input_file.get(current_char))
  {
    if (current_char == '\n')
    {
      line_count++;
    }
  }
  int read_nums[line_count] = {0};

  // reset file reader to beginning
  input_file.clear();
  input_file.seekg(0);

  // read lines from file and store to array
  string line;
  int i = 0;
  while (getline(input_file, line))
  {
    trim(line);
    if (line != "")
    {
      // fill array with numbers
      int num = stoi(line);
      read_nums[i] = num;
      i++;
    }
  }

  input_file.close();

  bubble_sort(read_nums, sizeof(read_nums) / sizeof(read_nums[0]));

  // multiply in-between 2 largest and 2 smallest numbers, and compare the multiplications
  int sm_num_1 = read_nums[0];
  int sm_num_2 = read_nums[1];
  int sm_mult = sm_num_1 * sm_num_2;

  int lg_num_1 = read_nums[line_count - 1];
  int lg_num_2 = read_nums[line_count - 2];
  int lg_mult = lg_num_1 * lg_num_2;

  if (sm_mult < lg_mult)
  {
    cout << "Largest product: " << lg_mult << endl;
  }
  else
  {
    cout << "Largest product: " << sm_mult << endl;
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

// basic bubble sort implementation (with help of ChatGPT)
void bubble_sort(int arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      // swap if the element found is greater than the next element
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}