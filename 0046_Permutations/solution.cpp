/*
46. Permutations

Given a collection of distinct integers, return all possible permutations.

https://leetcode.com/problems/permutations/

*/

#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> permute(vector<int> &nums)
  {
    vector<vector<int>> ans;
    vector<int> curr;
    vector<int> used(nums.size());
    dfs(nums, used, curr, ans);

    return ans;
  }

private:
  void dfs(const vector<int> &nums, vector<int> &used, vector<int> &curr, vector<vector<int>> &ans)
  {
    if (curr.size() == nums.size())
    {
      ans.push_back(curr);
      return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
      if (used[i])
        continue;

      curr.push_back(nums[i]);
      used[i] = 1;
      dfs(nums, used, curr, ans);
      curr.pop_back();
      used[i] = 0;
    }
  }
};

class Solution_STL
{
  vector<vector<int>> permute(vector<int> &nums)
  {
    int len = nums.size();
    vector<vector<int>> result;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    do
    {
      for (int i = 0; i < len; i++)
        temp.push_back(nums[i]);
      result.push_back(temp);
      temp.clear();
    } while (next_permutation(nums.begin(), nums.end()));

    return result;
  }
};