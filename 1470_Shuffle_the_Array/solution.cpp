/*
1470. Shuffle the Array

Level: Easy

https://leetcode.com/problems/shuffle-the-array
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
  vector<int> shuffle(vector<int> &nums, int n)
  {
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
      res.push_back(nums[i]);
      res.push_back(nums[i + n]);
    }
    return res;
  }

  vector<int> shuffle2(vector<int> &nums, int n)
  {
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
      res.push_back(nums[i]);
      res.push_back(nums[i + n]);
    }
    return nums;
  }
};