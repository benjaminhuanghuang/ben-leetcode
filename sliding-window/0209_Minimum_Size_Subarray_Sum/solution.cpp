/*
209. Minimum Size Subarray Sum

https://leetcode.com/problems/minimum-size-subarray-sum/
*/
#include <vector>

using namespace std;
/*
Solution 1: Two Pointers (Sliding Window)

Maintain a sliding window [l, r) such that sum(nums[l:r)) >= s, then move l to l + 1, 
and move r accordingly to make the window valid.

Time complexity: O(n)
Space complexity: O(1)
*/
class Solution
{
public:
  int minSubArrayLen(int s, vector<int> &nums)
  {
    int l = 0;
    int r = 0;
    int t = 0;
    int ans = INT_MAX;
    while (l < nums.size())
    {
      while (t < s && r < nums.size())
        t += nums[r++];
      if (t < s)
        break;
      ans = min(ans, r - l);
      t -= nums[l++];
    }
    return ans == INT_MAX ? 0 : ans;
  }
};