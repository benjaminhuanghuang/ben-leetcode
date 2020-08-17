/*
1186. Maximum Subarray Sum with One Deletion

Level: Medium

https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion
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
  Solution: DP

    First, handle the special case: all numbers are negative, return the max one.

    s0 = max subarray sum ends with a[i]
    s1 = max subarray sum ends with a[i] with at most one deletion

    whenever s0 or s1 becomes negative, reset them to 0.

    Time complexity: O(n)
    Space complexity: O(1)
*/

class Solution
{
public:
  int maximumSum(vector<int> &arr)
  {
    int m = *max_element(begin(arr), end(arr));
    if (m <= 0)
      return m;

    int s0 = 0;
    int s1 = 0;
    int ans = 0;

    for (int a : arr)
    {
      s1 = max(s0, s1 + a);
      s0 += a;
      ans = max(ans, max(s0, s1));
      if (s0 < 0)
        s0 = 0;
      if (s1 < 0)
        s1 = 0;
    }

    return ans;
  }
};