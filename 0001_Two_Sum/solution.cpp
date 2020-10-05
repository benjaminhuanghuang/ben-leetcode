/*
1. Two Sum

https://leetcode.com/problems/two-sum/
*/
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <assert.h> /* assert */

using namespace std;
/*
https://www.youtube.com/watch?v=jfb72FfxWKU
 */
class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> indies;

    for (int i = 0; i < nums.size(); i++)
    {
      int diff = target - nums[i];
      if (indies.count(diff))
      {
        return {indies[diff], i};
      }
      else
      {
        indies[nums[i]] = i;
      }
    }
    // generalized initializer lists are a C++11 extension
    return {};
  }
};

class Solution_Sorted
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    //sort(nums.begin(), nums.end());

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
};

int main()
{
  vector<int> nums{2, 7, 11, 15};

  Solution s;
  vector<int> res = s.twoSum(nums, 9);

  assert(res.size() == 2);
  assert(res[0] == 0);
  assert(res[1] == 1);

  return 0;
}