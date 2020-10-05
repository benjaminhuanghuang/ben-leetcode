#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

/*
  Solution: 
*/
 vector<int> twoSum(vector<int> &nums, int target)
  {
    sort(nums.begin(), nums.end());

    int l = 0;
    int r = nums.size() - 1;

    while (l < r)
    {
      int sum = nums[l] + nums[r];
      if (sum == target)
      {
        return {l, r};
      }
      else if (sum < target)
      {
        l++;
      }
      else
      {
        r--;
      }
    }
    // generalized initializer lists are a C++11 extension
    return {};
  }
int numSpecial(vector<vector<int>> &mat)
{
  int ans = 0;

  // if the row only a 1 (rowSum == 1), put the col of the 1 into this vector.
  vector<int> cols;

  for (int row = 0; row < mat.size(); row++)
  {
    int findCol = -1;
    int rowSum = 0;
    for (int col = 0; col < mat[0].size(); col++)
    {
      rowSum += mat[row][col];
      if (mat[row][col] == 1)
      {
        findCol = col;
      }
    }
    if (rowSum == 1 && findCol > 0)
    {
      cols.push_back(findCol);
    }
  }

  // check the sum of the cols
  for (auto col : cols)
  {
    int colSum = 0;
    for (int row = 0; row < mat.size(); row++)
    {
      colSum += mat[row][col];
    }
    if (colSum == 1)
    {
      ans++;
    }
  }

  return ans;
}

int main()
{
  vector<int> nums = {3, 2,4};
  int target = 6;
  auto result = twoSum(nums, target);
  cout << result.size() << endl;
  return 0;
}