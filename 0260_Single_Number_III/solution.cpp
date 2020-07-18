/*
260. Single Number III

Level: Medium

https://leetcode.com/problems/single-number-iii
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
 two elements appear only once and all the other elements appear exactly twice.
*/
/*
  Solution: 
  https://www.youtube.com/watch?v=3TSC0nlur58
  
*/

class Solution
{
public:
  vector<int> singleNumber(vector<int> &nums)
  {
    int axorb = 0;
    for (int n : nums)
      axorb ^= n; // 得到的是只出现了一次的两个数字的异或。
    
    int a = 0, b = 0;
    int mask = 1;
    // find out the lowest 1 in the axorb
    while ((mask & axorb) == 0)
      mask <<= 1;

    for (int n : nums)
    {
      if (n & mask)
        a ^= n;
      else
        b ^= n;
    }
    return {a, b};
  }
};