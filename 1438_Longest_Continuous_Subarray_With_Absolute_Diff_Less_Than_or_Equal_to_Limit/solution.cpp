/*
1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

Level: Medium

https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: Sliding window
  https://zxi.mytechroad.com/blog/queue/leetcode-1438-longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
  
*/

class Solution
{
public:
  int longestSubarray(vector<int> &nums, int limit)
  {
    multiset<int> s;
    int l = 0;
    int ans = 0;
    for (int r = 0; r < nums.size(); ++r)
    {
      s.insert(nums[r]);
      while (*rbegin(s) - *begin(s) > limit)
        s.erase(s.equal_range(nums[l++]).first);
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};