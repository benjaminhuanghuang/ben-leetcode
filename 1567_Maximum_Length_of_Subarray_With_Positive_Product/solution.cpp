/*
1567. Maximum Length of Subarray With Positive Product

Level: Medium

https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product
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

  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1567-maximum-length-of-subarray-with-positive-product/
*/

class Solution
{
public:
  int getMaxLen(vector<int> &nums)
  {
    int p = 0;
    int n = 0;
    int ans = 0;
    for (int x : nums)
    {
      if (x > 0)
      {
        ++p;
        if (n)
          ++n;
      }
      else if (x < 0)
      {
        int tp = p;
        p = n ? n + 1 : 0;
        n = tp + 1;
      }
      else
      {
        p = n = 0;
      }
      ans = max(ans, p);
    }
    return ans;
  }
};