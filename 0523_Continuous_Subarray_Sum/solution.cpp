/*
523. Continuous Subarray Sum

Level: Medium

https://leetcode.com/problems/continuous-subarray-sum
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
  Time O(N^2)
*/

class Solution
{
public:
  bool checkSubarraySum(vector<int> &nums, int k)
  {
    for (int i = 0; i < nums.size() - 1; i++)
    {
      int sum = nums[i];
      for (int j = i + 1; j < nums.size(); j++)
      {
        sum += nums[j];
        if (sum == k) // for case nums=[0,0], k = 0
          return true;
        if (k != 0 && sum % k == 0)
          return true;
      }
    }
    return false;
  }
};

/*
  (sum1-sum2) % k =0  =>   sum1%k == sum2%k
*/
class Solution_prefix_sum
{
public:
  bool checkSubarraySum(vector<int> &nums, int k)
  {

    unordered_map<int, int> m;
    m[0] = -1;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      sum += nums[i];
      if (k != 0)
      {
        sum = sum % k;
      }
      if (m.count(sum))
      {
        if (i - m[sum] >= 2)
        {
          return true;
        }
      }
      else
      {
        m[sum] = i;
      }
    }
    return false;
  }
};