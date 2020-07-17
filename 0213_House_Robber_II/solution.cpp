/*
213. House Robber II

Level: Medium

https://leetcode.com/problems/house-robber-ii

# 198. House Robber

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
  int rob(vector<int> &nums)
  {
    if (nums.size() == 1)
      return nums[0];
    // skip first one;
    int max1 = maxRob(nums, 1, nums.size() - 1);
    // skip last one
    int max2 = maxRob(nums, 0, nums.size() - 2);

    return max(max1, max2);
  }

  int maxRob(vector<int> &nums, int start, int end)
  {
    int count = 1;   // not 0
    int sumOdd = 0;
    int sumEven = 0;
    for (int i = start; i <= end; i++)
    {
      if (count % 2)
        // curr is odd, rob curr or skip curr
        sumOdd = max(sumOdd + nums[i], sumEven);  
      else
        sumEven = max(sumEven + nums[i], sumOdd);
      count++;
    }
    return max(sumOdd, sumEven);
  }
};