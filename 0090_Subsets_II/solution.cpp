/*
90. Subsets II

https://leetcode.com/problems/subsets-ii/
*/
#include <vector>

using namespace std;

/*
*/

class Solution
{
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {
    vector<vector<int>> ans;
    vector<int> curr;
    sort(nums.begin(), nums.end());

    for (int n = 0; n <= nums.size(); n++)   // [0, nums.size()]
    {
      dfs(nums, n, 0, curr, ans);
    }
    return ans;
  }

  void dfs(vector<int> &nums, int n, int start, vector<int> curr, vector<vector<int>> &ans)
  {
    if (start == n)
    {
      ans.push_back(curr);
      return;
    }

    for (int i = start; i < n; i++)
    {
      if (i > start && nums[i] == nums[i - 1])   // remove duplicated
        continue;
      curr.push_back(nums[i]);
      dfs(nums, n, i+1, curr, ans);
      curr.pop_back();
    }
  }
};