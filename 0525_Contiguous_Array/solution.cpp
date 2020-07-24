/*
525. Contiguous Array

Level: Medium

https://leetcode.com/problems/contiguous-array
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
    https://zxi.mytechroad.com/blog/hashtable/leetcode-525-contiguous-array/

    
    0 -> -1 => sum of subarray is 0
    Prefix sum + hashtable

    Time complexity: O(n)

    Space complexity: O(n)
*/

class Solution
{
public:
  int findMaxLength(vector<int> &nums)
  {
    if (nums.empty())
      return 0;

    unordered_map<int, int> pos;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      // prefix sum
      sum += nums[i] ? 1 : -1;
      if (sum == 0)
      {
        ans = i + 1;
      }
      else if (pos.count(sum))
      {
        ans = max(ans, i - pos[sum]);
      }
      else
      {
        pos[sum] = i;
      }
    }
    return ans;
  }
};