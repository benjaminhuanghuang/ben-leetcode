/*
462. Minimum Moves to Equal Array Elements II

Level: Medium

https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii
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
  int minMoves2(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    int count = 0;
    while (i < j)
    {
      count += nums[j] - nums[i];
      i++;
      j--;
    }
    return count;
  }
};