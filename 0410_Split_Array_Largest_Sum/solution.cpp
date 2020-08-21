/*
410. Split Array Largest Sum

Level: Hard

https://leetcode.com/problems/split-array-largest-sum
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
  Solution: Recursion + Memorization
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-410-split-array-largest-sum/
*/

class Solution
{
public:
  int splitArray(vector<int> &nums, int m)
  {
    const int n = nums.size();
    sums_ = vector<int>(n);
    mem_ = vector<vector<int>>(n, vector<int>(m + 1, INT_MAX));
    sums_[0] = nums[0];
    for (int i = 1; i < n; ++i)
      sums_[i] = sums_[i - 1] + nums[i];
    return splitArray(nums, n - 1, m);
  }

private:
  vector<vector<int>> mem_;
  vector<int> sums_;

  // min of largest sum of spliting nums[0] ~ nums[k] into m groups
  int splitArray(const vector<int> &nums, int k, int m)
  {
    if (m == 1)
      return sums_[k];
    if (m > k + 1)
      return INT_MAX;
    if (mem_[k][m] != INT_MAX)
      return mem_[k][m];
    int ans = INT_MAX;
    for (int i = 0; i < k; ++i)
      ans = min(ans, max(splitArray(nums, i, m - 1), sums_[k] - sums_[i]));
    return mem_[k][m] = ans;
  }
};

/*
  Solution: Binary Search

  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-410-split-array-largest-sum/
*/
class Solution
{
public:
  int splitArray(vector<int> &nums, int m)
  {
    long l = *max_element(begin(nums), end(nums));
    long r = accumulate(begin(nums), end(nums), 0L) + 1;
    while (l < r)
    {
      long limit = (r - l) / 2 + l;
      if (min_groups(nums, limit) > m)
        l = limit + 1;
      else
        r = limit;
    }
    return l;
  }

private:
  int min_groups(const vector<int> &nums, long limit)
  {
    long sum = 0;
    int groups = 1;
    for (int num : nums)
    {
      if (sum + num > limit)
      {
        sum = num;
        ++groups;
      }
      else
      {
        sum += num;
      }
    }
    return groups;
  }
};