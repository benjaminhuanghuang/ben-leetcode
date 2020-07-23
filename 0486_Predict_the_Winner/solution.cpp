/*
486. Predict the Winner

Level: Medium

https://leetcode.com/problems/predict-the-winner
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  bool PredictTheWinner(vector<int> &nums)
  {
  }
};
/*
  Time complexity: O(2^n)

  Space complexity: O(n)
*/
class Solution
{
public:
  bool PredictTheWinner(vector<int> &nums)
  {
    return helper(nums, 0, nums.size() - 1) >= 0;
  }

private:
  int helper(vector<int> &nums, int start, int end)
  {
    if (start == end)
    {
      //如果只剩一个元素，player1能拿到的分数就是这个元素,player2能拿到分数为0，两人分数差为0
      return nums[start];
    }
    else
    {
      //player1 与 player2的分数之差
      return max(nums[start] - helper(nums, start + 1, end), nums[end] - helper(nums, start, end - 1));
    }
  }
};

/*
Solution 2: Recursion + Memoization

Time complexity: O(n^2)    l * r   

Space complexity: O(n)
*/
class Solution {
public:
  bool PredictTheWinner(vector<int>& nums) {
    m_ = vector<vector<int>>(nums.size(), vector<int>(nums.size(), INT_MIN));
    return getScore(nums, 0, nums.size() - 1) >= 0;
  }
private:
  vector<vector<int>> m_;
  // Max diff (my_score - op_score) of subarray nums[l] ~ nums[r].
  int getScore(vector<int>& nums, int l, int r) {
    if (l == r) return nums[l];    
    if (m_[l][r] != INT_MIN) return m_[l][r];
    m_[l][r] = max(nums[l] - getScore(nums, l + 1, r), 
                   nums[r] - getScore(nums, l, r - 1));
    return m_[l][r];
  }    
};

/*
 DP

*/ 
class Solution {
public:
  bool PredictTheWinner(vector<int>& nums) {
    const int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
    for (int i = 0; i < n; ++i)
      dp[i][i] = nums[i];
    for (int l = 2; l <= n; ++l)
      for (int i = 0; i <= n - l; ++i) {
        int j = i + l - 1;
        dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
      }
    return dp[0][n - 1] >= 0;
  }
};

