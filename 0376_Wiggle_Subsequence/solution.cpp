/*
376. Wiggle Subsequence

Level: Medium

https://leetcode.com/problems/wiggle-subsequence
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
  //http://www.cnblogs.com/grandyang/p/5697621.html
  // 如果当前数字比前一个数字大，则p=q+1，如果比前一个数字小，则q=p+1，
  // 最后取p和q中的较大值跟n比较，取较小的那个：
*/

class Solution
{
public:
  int wiggleMaxLength(vector<int> &nums)
  {
    if (nums.size() == 0)
      return 0;
    int n = nums.size();
    int p = 1, q = 1;
    for (int i = 1; i < n; ++i)
    {
      if (nums[i] > nums[i - 1])
        p = q + 1;
      else if (nums[i] < nums[i - 1])
        q = p + 1;
    }
    return min(n, max(p, q));
  }
};