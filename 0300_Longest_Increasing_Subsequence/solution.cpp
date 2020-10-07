/*
300. Longest Increasing Subsequence

Level: Medium

https://leetcode.com/problems/longest-increasing-subsequence
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

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
  /*
      所有的sub sequence 有 O(2^N)个
    */
  int lengthOfLIS_bruteforce(vector<int> &nums)
  {
  }

  /*
    DP
    O(N^2)
  */
  int lengthOfLIS(vector<int> &nums)
  {
    if (nums.empty())
      return 0;
    int n = nums.size();
    auto dp = vector<int>(n, 1);
    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (nums[i] > nums[j])
          dp[i] = max(dp[i], dp[j] + 1);
    return *max_element(dp.begin(), dp.end());
  }

  /*
    recursion + memoization
  */
  int lengthOfLIS(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 0)
      return 0;
    f_ = vector<int>(n, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i)
      ans = max(ans, LIS(nums, i));
    return ans;
  }

private:
  vector<int> f_;
  // length of LIS ends with nums[r]
  int LIS(const vector<int> &nums, int r)
  {
    if (r == 0)
      return 1;
    if (f_[r] > 0)
      return f_[r];
    int ans = 1;
    for (int i = 0; i < r; ++i)
      if (nums[r] > nums[i])
        ans = max(ans, LIS(nums, i) + 1);
    f_[r] = ans;
    return f_[r];
  }
};