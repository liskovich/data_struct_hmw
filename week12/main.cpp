#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> two_sum(vector<int> &nums, int target)
{
  unordered_map<int, int> num_map;
  vector<int> result;

  for (int i = 0; i < nums.size(); i++)
  {
    // find a complement for each number we check
    int complement = target - nums[i];

    // if it exists in the nums, then we found the solution
    if (num_map.find(complement) != num_map.end())
    {
      result.push_back(num_map[complement]);
      result.push_back(i);
      break;
    }
    num_map[nums[i]] = i;
  }
  return result;
}

int main()
{
  ifstream inputFile("two_sum_target_n_data.txt");

  // read target integer
  int target;
  inputFile >> target;

  // skip empty line
  string empty_line;
  getline(inputFile, empty_line);

  // read nums into vector
  vector<int> nums;
  int num;
  while (inputFile >> num)
  {
    nums.push_back(num);
  }

  inputFile.close();

  vector<int> indices = two_sum(nums, target);
  if (indices.size() == 2)
  {
    cout << indices[0] << endl;
    cout << indices[1] << endl;
  }
  else
  {
    cout << "no solution" << endl;
  }

  return 0;
}
