/*
1144. Decrease Elements To Make Array Zigzag

Level: Medium

https://leetcode.com/problems/decrease-elements-to-make-array-zigzag
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
  https://zxi.mytechroad.com/blog/greedy/leetcode-1144-decrease-elements-to-make-array-zigzag/
*/

class Solution
{
public:
  int movesToMakeZigzag(vector<int> &nums)
  {
    const int n = nums.size();
    vector<int> moves(2);
    for (int i = 0; i < n; i++)
    {
      int l = i == 0 ? INT_MAX : nums[i - 1];
      int r = i == n - 1 ? INT_MAX : nums[i + 1];
      moves[i % 2] += max(0, nums[i] - min(l, r) + 1);
    }
    return min(moves[0], moves[1]);
  }
};