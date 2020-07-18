/*
334. Increasing Triplet Subsequence

Level: Medium

https://leetcode.com/problems/increasing-triplet-subsequence
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
  bool increasingTriplet(vector<int> &nums)
  {
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    for (int num : nums)
    {
      if (num > min2)
        return true;
      else if (num < min1)
      {
        min1 = num;
      }
      else if (num > min1 && num < min2)
      {
        min2 = num;
      }
    }
    return false;
  }
};