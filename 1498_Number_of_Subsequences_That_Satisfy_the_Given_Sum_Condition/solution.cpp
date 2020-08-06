/*
1498. Number of Subsequences That Satisfy the Given Sum Condition

Level: Medium

https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition
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
  https://zxi.mytechroad.com/blog/two-pointers/leetcode-1498-number-of-subsequences-that-satisfy-the-given-sum-condition/
*/

class Solution
{
public:
  int numSubseq(vector<int> &nums, int target)
  {
    constexpr int kMod = 1e9 + 7;
    const int n = nums.size();
    vector<int> p(n + 1, 1);
    for (int i = 1; i <= n; ++i)
      p[i] = (p[i - 1] << 1) % kMod;
    sort(begin(nums), end(nums));
    int ans = 0;
    for (int i = 0, j = n - 1; i <= j; ++i)
    {
      while (i <= j && nums[i] + nums[j] > target)
        --j;
      if (i > j)
        continue;
      // In subarray nums[i~j]:
      // min = nums[i], max = nums[j]
      // nums[i] + nums[j] <= target
      // {nums[i], (j - i - 1 + 1 values)}
      // Any subset of the right part gives a valid subsequence
      // in the original array. And There are 2^(j - i) ones.
      ans = (ans + p[j - i]) % kMod;
    }
    return ans;
  }
};