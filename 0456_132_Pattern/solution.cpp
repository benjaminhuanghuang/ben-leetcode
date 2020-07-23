/*
456. 132 Pattern

Level: Medium

https://leetcode.com/problems/132-pattern
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
  bool find132pattern(vector<int> &nums)
  {
    int n = nums.size(), i = 0, j = 0, k = 0;
    while (i < n)
    {
      while (i < n - 1 && nums[i] >= nums[i + 1])
        ++i;
      j = i + 1;
      while (j < n - 1 && nums[j] <= nums[j + 1])
        ++j;
      k = j + 1;
      while (k < n)
      {
        if (nums[k] > nums[i] && nums[k] < nums[j])
          return true;
        ++k;
      }
      i = j + 1;
    }
    return false;
  }
};