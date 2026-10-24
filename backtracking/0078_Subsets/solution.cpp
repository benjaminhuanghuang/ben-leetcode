/*
  78. Subsets

  https://leetcode.com/problems/subsets/
*/

#include <vector>
#include <algorithm>

using namespace std;

/*
https://zxi.mytechroad.com/blog/searching/leetcode-78-subsets/ [一定要看]

Time complexity: O(2^n)
Space complexity: O(n)
*/
class Solution
{
public:
  vector<vector<int>> subsets(vector<int> &nums)
  {
    vector<vector<int>> ans;
    vector<int> curr;
    sort(nums.begin(), nums.end());

    for (int n = 0; n <= nums.size(); n++)   // Note, []  is one of the answer
    {
      dfs(nums, curr, n, 0, ans);
    }

    return ans;
  }

private:
  void dfs(vector<int> &nums, vector<int> &curr, int n, int start, vector<vector<int>> &ans)
  {
    if (start == n)
    {
      ans.push_back(curr);
      return;
    }

    for (int i = start; i < n; i++)
    {
      curr.push_back(nums[i]);
      dfs(nums, curr, n, i + 1, ans);
      curr.pop_back();
    }
  }
};