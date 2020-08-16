/*
1283. Find the Smallest Divisor Given a Threshold

Level: Medium

https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold
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
  int smallestDivisor(vector<int> &nums, int threshold)
  {
    auto sums = [&](int d) {
      int s = 0;
      for (int n : nums)
        s += (n + (d - 1)) / d;   //向上取整
      return s;
    };

    int l = 1;
    int r = 1e6;
    while (l < r)
    {
      int m = l + (r - l) / 2;
      if (sums(m) <= threshold)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};