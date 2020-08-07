/*
1508. Range Sum of Sorted Subarray Sums

Level: Medium

https://leetcode.com/problems/range-sum-of-sorted-subarray-sums
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
  
  Solution: Brute Force
  https://zxi.mytechroad.com/blog/queue/leetcode-1508-range-sum-of-sorted-subarray-sums/
*/

class Solution_BruteForce
{
public:
  int rangeSum(vector<int> &nums, int n, int left, int right)
  {
    constexpr int kMod = 1e9 + 7;
    vector<int> sums;

    for (int i = 0; i < n; ++i)
      for (int j = i, sum = 0; j < n; ++j)
        sums.push_back(sum += nums[j]);

    sort(begin(sums), end(sums));
    return accumulate(begin(sums) + left - 1, begin(sums) + right, 0LL) % kMod;
  }
};

/*
  Solution 2: Priority Queue / Min Heap

  https://zxi.mytechroad.com/blog/queue/leetcode-1508-range-sum-of-sorted-subarray-sums/
*/
struct Entry {
  int sum;
  int i;
  bool operator<(const Entry& e) const { return sum > e.sum; }
};
 
class Solution {
public:
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    constexpr int kMod = 1e9 + 7;
    priority_queue<Entry> q; // Sort by e.sum in descending order.
    for (int i = 0; i < n; ++i)
      q.push({nums[i], i});
    long ans = 0;
    for (int j = 1; j <= right; ++j) {
      const auto e = std::move(q.top()); q.pop();
      if (j >= left) ans += e.sum;
      if (e.i + 1 < n) q.push({e.sum + nums[e.i + 1], e.i + 1});
    }
    return ans % kMod;
  }
};