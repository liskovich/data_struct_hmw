#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main()
{
  string file_path = "2d.csv";

  // checking if file can be opened
  ifstream file(file_path);
  if (!file.is_open())
  {
    cerr << "Error opening file: " << file_path << endl;
    return 1;
  }

  // read and skip the first row with column names
  string line;
  getline(file, line);

  // read in the numbers from columns and rows
  vector<vector<int>> data;
  while (getline(file, line))
  {
    string value_str;
    vector<int> row;

    // iterate through chars in a line and check if it is not a comma
    for (char c : line)
    {
      if (c == ',')
      {
        // convert string to int
        row.push_back(stoi(value_str));
        value_str = "";
      }
      else
      {
        value_str += c;
      }
    }
    row.push_back(stoi(value_str));
    data.push_back(row);
  }

  // create separately all 3 columns
  vector<int> col_1;
  vector<int> col_2;
  vector<int> col_3;
  for (auto &row : data)
  {
    col_1.push_back(row[0]);
    col_2.push_back(row[1]);
    col_3.push_back(row[2]);
  }

  // find min value in column 1
  int min_val = *min_element(col_1.begin(), col_1.end());
  cout << "Column 1: min value = " << min_val << endl;

  // find arithmetic mean in column 2
  double mean = (double)accumulate(col_2.begin(), col_2.end(), 0) / (double)col_2.size();
  mean = ceil(mean * 100.0) / 100.0;
  cout << "Column 2: arithmetic mean = " << mean << endl;

  // find arithmetic mean in column 3 (for further calculations)
  double mean_3 = accumulate(col_3.begin(), col_3.end(), 0) / col_3.size();
  mean_3 = ceil(mean_3 * 100.0) / 100.0;

  // find population standard deviation column 3
  double accumulated = 0.0;
  for (auto &row : col_3)
  {
    accumulated += pow(row - mean_3, 2);
  }
  double deviation = sqrt(accumulated / col_3.size());
  deviation = ceil(deviation * 100.0) / 100.0;
  cout << "Column 3: population standard deviation = " << deviation << endl;

  // clear allocated memory
  for (auto &row : data)
  {
    row.clear();
  }
  data.clear();
  col_1.clear();
  col_2.clear();
  col_3.clear();

  return 0;
}
