/*
1480. Running Sum of 1d Array

Level: Easy

https://leetcode.com/problems/running-sum-of-1d-array
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
  vector<int> runningSum(vector<int> &nums)
  {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      int n = nums[i];
      nums[i] = n + sum;
      sum += n;
    }
    return nums;
  }
};