/*
1546. Maximum Number of Non-Overlapping Subarrays With Sum Equals Target

Level: Medium

https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target
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
  int maxNonOverlapping(vector<int> &nums, int target)
  {
    const int n = nums.size();
    vector<int> dp(n + 1, 0);      // ans at nums[i];
    unordered_map<int, int> index; // {prefix sum -> last_index}
    index[0] = -1;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
      sum += nums[i];
      int t = sum - target;
      dp[i + 1] = dp[i];
      if (index.count(t))
        dp[i + 1] = max(dp[i + 1], dp[index[t] + 1] + 1);
      index[sum] = i;
    }
    return dp[n];
  }
};