/*
330. Patching Array

Level: Hard

https://leetcode.com/problems/patching-array
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  https://www.cnblogs.com/grandyang/p/5165821.html
*/

class Solution
{
public:
  int minPatches(vector<int> &nums, int n)
  {
    long miss = 1, res = 0, i = 0;
    while (miss <= n)
    {
      if (i < nums.size() && nums[i] <= miss)
      {
        miss += nums[i++];
      }
      else
      {
        miss += miss;
        ++res;
      }
    }
    return res;
  }
};