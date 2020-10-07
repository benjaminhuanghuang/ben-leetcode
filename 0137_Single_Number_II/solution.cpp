/*
137. Single Number II

Level: Medium

https://leetcode.com/problems/single-number-ii
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
  对每一位进行   sum % 3
*/

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    int res = 0;
    for (int i = 0; i < 32; ++i)
    {
      int sum = 0;
      for (int j = 0; j < nums.size(); ++j)
      {
        // 第 i 位
        sum += (nums[j] >> i) & 1;
      }
      res |= (sum % 3) << i;
    }
    return res;
  }
};