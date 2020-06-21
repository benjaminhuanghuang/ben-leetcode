/*
198. House Robber

Level: Easy

https://leetcode.com/problems/house-robber
*/
#include <vector>
#include <string>
#include <unordered_set>

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
    int len = nums.size();
    int odd = 0, even = 0;
    for (int i = 0; i < len; i++)
    {
      if (i % 2 == 0)
        even = max(odd, even + nums[i]);
      else
        odd = max(even, odd + nums[i]);
    }

    return max(odd, even);
  }
};