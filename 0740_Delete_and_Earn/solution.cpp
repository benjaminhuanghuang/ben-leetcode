/*
740. Delete and Earn

Level: Medium

https://leetcode.com/problems/delete-and-earn

# 198. House Robber
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
    Time complexity: O(n + r)
    Space complexity: O(r)

    http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-740-delete-and-earn/
    
*/

class Solution
{
public:
  int deleteAndEarn(vector<int> &nums)
  {
    if (nums.empty())
      return 0;
    const auto range = minmax_element(nums.begin(), nums.end());
    const int l = *(range.first);
    const int r = *(range.second);
    vector<int> points(r - l + 1, 0);
    for (const int num : nums)
      points[num - l] += num;
    return rob(points);
  }

private:
  // From LeetCode 198. House Robber
  int rob(const vector<int> &nums)
  {
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