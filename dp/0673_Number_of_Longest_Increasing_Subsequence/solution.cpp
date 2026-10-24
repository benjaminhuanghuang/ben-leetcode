/*
673. Number of Longest Increasing Subsequence

Level: Medium

https://leetcode.com/problems/number-of-longest-increasing-subsequence
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
  http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-673-number-of-longest-increasing-subsequence/
*/

class Solution
{
public:
  int findNumberOfLIS(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 0)
      return 0;

    vector<int> c(n, 1);
    vector<int> l(n, 1);

    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (nums[i] > nums[j])
        {
          if (l[j] + 1 > l[i])
          {
            l[i] = l[j] + 1;
            c[i] = c[j];
          }
          else if (l[j] + 1 == l[i])
          {
            c[i] += c[j];
          }
        }

    int max_len = *max_element(l.begin(), l.end());

    int ans = 0;
    for (int i = 0; i < n; ++i)
      if (l[i] == max_len)
        ans += c[i];

    return ans;
  }
};