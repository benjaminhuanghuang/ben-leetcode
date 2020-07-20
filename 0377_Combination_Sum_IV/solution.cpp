/*
377. Combination Sum IV

Level: Medium

https://leetcode.com/problems/combination-sum-iv
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

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0); // dp[i] # of combinations sum up to i
        dp[0] = 1;
        for (int i = 1; i <= target; ++i)
            for (const int num : nums)
                if (i - num >= 0)
                    dp[i] += dp[i - num];           
        return dp[target];
    }
};
/*
  Recursion + Memorization
*/
class Solution
{
public:
  int combinationSum4(vector<int> &nums, int target)
  {
    m_ = vector<int>(target + 1, -1);
    m_[0] = 1;
    return dp(nums, target);
  }

private:
  int dp(const vector<int> &nums, int target)
  {
    if (target < 0)
      return 0;
    if (m_[target] != -1)
      return m_[target];
    int ans = 0;
    for (const int num : nums)
      ans += dp(nums, target - num);
    return m_[target] = ans;
  }
  // 每个target的解的数量
  vector<int> m_;
};