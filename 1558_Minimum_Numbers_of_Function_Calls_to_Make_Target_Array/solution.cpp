/*
1558. Minimum Numbers of Function Calls to Make Target Array

Level: Medium

https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array
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
  https://zxi.mytechroad.com/blog/bit/leetcode-1558-minimum-numbers-of-function-calls-to-make-target-array/
*/

class Solution
{
public:
  int minOperations(vector<int> &nums)
  {
    int ans = 0;
    int high = 0;
    for (int x : nums)
    {
      high = max(high, 31 - __builtin_clz(x | 1));
      ans += std::bitset<32>(x).count();
    }
    return ans + high;
  }
};