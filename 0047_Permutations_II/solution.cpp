/*
47. Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations
https://leetcode.com/problems/permutations-ii/
*/

#include <vector>
#include <algorithm>

using namespace std;

/*
https://zxi.mytechroad.com/blog/searching/leetcode-47-permutations-ii/

Time complexity: O(n!)
Space complexity: O(n + k)
时间复杂度：递归被调用的次数与解的个数一样是n!次，每次有个for循环，那么总时间复杂度是O(n*n!)
空间复杂度：与调用递归次数一样O(n!)
*/
class Solution
{
public:
  vector<vector<int>> permuteUnique(vector<int> &nums)
  {
    vector<vector<int>> ans;
    vector<int> curr;
    sort(nums.begin(), nums.end());    // 和46 的不同
    vector<int> used(nums.size());

    dfs(nums, used, curr, ans);

    return ans;
  }

private:
  void dfs(vector<int> &nums, vector<int> &used, vector<int> &curr, vector<vector<int>> &ans)
  {
    if (curr.size() == nums.size())
    {
      ans.push_back(curr);
      return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
      // Same number can be only used once at each depth.
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])   //和46的不同
        continue;

      if (used[i])
        continue;

      used[i] = 1;
      curr.push_back(nums[i]);
      dfs(nums, used, curr, ans);
      curr.pop_back();
      used[i] = 0;
    }
  }
};