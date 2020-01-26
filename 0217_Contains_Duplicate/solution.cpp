/*
217. Contains Duplicate

https://leetcode.com/problems/contains-duplicate/
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool containsDuplicate(vector<int> &nums)
  {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i)
    {
      if (m.find(nums[i]) != m.end())
        return true;
      ++m[nums[i]];
    }
    return false;
  }
};
/*
 Faster
*/
class Solution2
{
public:
  bool containsDuplicate(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); ++i)
    {
      if (nums[i] == nums[i - 1])
        return true;
    }
    return false;
  }
};