/*
216. Combination Sum III [Medium]

https://leetcode.com/problems/combination-sum-iii/
*/

#include <vector>

using namespace std;

/*
  https://zxi.mytechroad.com/blog/searching/leetcode-216-combination-sum-iii/


  Time complexity: C(m, k) = C(9, k) = 9!/k!/(9-ks)
  Space complexity: O(k + k*# of ans)
*/

class Solution
{
public:
  vector<vector<int>> combinationSum3(int k, int n)
  {
    vector<vector<int>> ans;
    vector<int> cur;
    dfs(k, n, 1, cur, ans);
    return ans;
  }

private:
  // Use k numbers (>= s) to sum up to n
  void dfs(int k, int n, int start, vector<int> &cur, vector<vector<int>> &ans)
  {
    if (k == 0 && n == 0)
    {
      ans.push_back(cur);
      return;
    }

    for (int i = start; i <= 9; ++i)
    {
      if (i > n)  // 剪枝
        return;
      cur.push_back(i);
      dfs(k - 1, n - i, i + 1, cur, ans);
      cur.pop_back();
    }
  }
};

/*
  https://zxi.mytechroad.com/blog/searching/leetcode-216-combination-sum-iii/


  Time complexity: C(2^m) = C(2^9)
  Space complexity: O(k + k*# of ans)
*/
class Solution_Binary
{
public:
  vector<vector<int>> combinationSum3(int k, int n)
  {
    vector<vector<int>> ans;

    // 2^9, generate all combinations of [1 .. 9]
    for (int i = 0; i < (1 << 9); ++i)
    {
      vector<int> cur;
      int sum = 0;
      // Use j if (j - 1)-th bit is 1
      for (int j = 1; j <= 9; ++j)
        if (i & (1 << (j - 1)))
        {
          sum += j;
          cur.push_back(j);
        }
      if (sum == n && cur.size() == k)
        ans.push_back(cur);
    }

    return ans;
  }
};