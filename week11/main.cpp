#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <locale>
#include <codecvt>
#include <cstring>

using namespace std;

// convert UTF-8 string to wstring
// inspired from: https://stackoverflow.com/a/18597384
wstring utf8_to_wstring(const string &str)
{
  wstring_convert<codecvt_utf8<wchar_t>> converter;
  return converter.from_bytes(str);
}

// lowercase a string
wstring to_lowercase(const wstring &str)
{
  wstring result;
  locale loc;
  for (wchar_t c : str)
  {
    result += tolower(c, loc);
  }
  return result;
}

// count character frequencies
// use unordered_map for that, inspired from: https://www.geeksforgeeks.org/frequency-of-each-character-in-a-string-using-unordered_map-in-c/
unordered_map<wchar_t, int> count_character_frequencies(const wstring &text)
{
  unordered_map<wchar_t, int> frequencies;
  for (wchar_t c : text)
  {
    frequencies[c]++;
  }
  return frequencies;
}

// function for sorting frequencies
bool compare_frequencies(const pair<wchar_t, int> &a, const pair<wchar_t, int> &b)
{
  return a.second > b.second;
}

int main(int argc, char **argv)
{
  bool lowercase = false;
  string input_filename;
  string output_filename;

  // parse CLI args
  if (argc < 2)
  {
    cout << "You must provide at least input file as argument" << endl;
    return 1;
  }

  for (int i = 1; i < argc; ++i)
  {
    if (strcmp(argv[i], "-l") == 0)
    {
      // enable lowercase flag
      lowercase = true;
    }
    else if (strcmp(argv[i], "-i") == 0 && i + 1 < argc)
    {
      // set input file
      input_filename = argv[++i];
    }
    else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc)
    {
      // set output file
      output_filename = argv[++i];
    }
  }

  // if no output specified, use input filename
  if (output_filename.empty())
  {
    size_t dot_position = input_filename.find_last_of(".");
    if (dot_position != string::npos)
    {
      output_filename = input_filename.substr(0, dot_position) + ".tsv";
    }
    else
    {
      output_filename = input_filename + ".tsv";
    }
  }

  // read input file data into wstring
  ifstream input_file(input_filename);
  if (!input_file)
  {
    cout << "Error: Unable to open input file" << endl;
    return 1;
  }
  string content((istreambuf_iterator<char>(input_file)), (istreambuf_iterator<char>()));
  wstring text = utf8_to_wstring(content);

  // lowercase text if specified
  if (lowercase)
  {
    text = to_lowercase(text);
  }

  // count character frequencies
  unordered_map<wchar_t, int> frequencies = count_character_frequencies(text);

  // sort frequencies in descending order
  vector<pair<wchar_t, int>> frequency_vector(frequencies.begin(), frequencies.end());
  sort(frequency_vector.begin(), frequency_vector.end(), compare_frequencies);

  // save result
  ofstream output_file(output_filename);
  if (!output_file)
  {
    cout << "Error: Unable to open output file" << endl;
    return 1;
  }
  output_file << "symbol\tcount" << endl;
  for (const auto &pair : frequency_vector)
  {
    output_file << char(pair.first) << "\t" << pair.second << endl;
  }
  return 0;
}
