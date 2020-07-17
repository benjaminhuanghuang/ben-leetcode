/*
198. House Robber

Level: Easy

https://leetcode.com/problems/house-robber
*/
#include <vector>
#include <string>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  https://www.youtube.com/watch?v=H75Qp7ExCwo

  Brute force : O(2^N), N 个房子，每个房子有两种情况


  Recurson + Memorization：
    每个房子两种option: 
      1. rob house i if did not rob house i -1 
      2. skip
    rob(n) = max(rob(n-2) + money[i],   rob(n-1))

    Time complexity O(N)
    Space complexity O(N)  

  DP:
    dp[i] = max(dp[n-2] + money[i],   dp[n-1])

    Time complexity O(N)
    Space complexity O(N)  -> O(1)
*/

/*
    Time complexity O(N)
    Space complexity O(N)  
*/
class Solution_Recursion
{
public:
  int rob(vector<int> &nums)
  {
    const int n = nums.size();
    m_ = vector<int>(n, -1); // init the memorization

    return rob(nums, n - 1); // 求解前n个房子，index is n -1
  }

private:
  int rob(const vector<int> &nums, int i)
  {
    if (i < 0)
      return 0;
    if (m_[i] >= 0) // 子问题被求解过
      return m_[i];
    return m_[i] = max(rob(nums, i - 2) + nums[i],
                       rob(nums, i - 1));
  }

  vector<int> m_;
};

/*
  Time complexity O(N)
  Space complexity O(N)  
*/
class Solution_DP
{
public:
  int rob(vector<int> &nums)
  {
    if (nums.empty())
      return 0;
    vector<int> dp(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i)
      // dp[i] = max(dp[n-2] + money[i],  dp[n-1])
      dp[i] = max((i > 1 ? dp[i - 2] : 0) + nums[i],
                  (i > 0 ? dp[i - 1] : 0));
    return dp.back();
  }
};

/*
  Time complexity O(N)
  Space complexity O(1)    dp[i] 只和 dp[i - 2]  dp[i - 1] 有关 
*/
class Solution_DP2
{
public:
  int rob(vector<int> &nums)
  {
    if (nums.empty())
      return 0;
    int dp2 = 0;
    int dp1 = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      int dp = max(dp2 + nums[i], dp1);
      dp2 = dp1;
      dp1 = dp;
    }
    return dp1;
  }
};

/*
  Solution: DP
*/
class Solution
{
public:
  int rob(vector<int> &nums)
  {
    int len = nums.size();
    int odd = 0, even = 0;
    for (int i = 0; i < len; i++)
    {
      if (i % 2 == 0)
        even = max(odd, even + nums[i]);
      else
        odd = max(even, odd + nums[i]);
    }

    return max(odd, even);
  }
};