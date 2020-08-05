/*
698. Partition to K Equal Sum Subsets

Level: Medium

https://leetcode.com/problems/partition-to-k-equal-sum-subsets
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
  bool canPartitionKSubsets(vector<int> &nums, int k)
  {
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0)
      return false;
    sort(nums.rbegin(), nums.rend());
    return dfs(nums, sum / k, 0, k, 0);
  }

private:
  bool dfs(const vector<int> &nums, int target, int cur, int k, int used)
  {
    if (k == 0)
      return used == (1 << nums.size()) - 1;
    for (int i = 0; i < nums.size(); ++i)
    {
      if (used & (1 << i))
        continue;
      int t = cur + nums[i];
      if (t > target)
        break; // Important
      int new_used = used | (1 << i);
      if (t == target && dfs(nums, target, 0, k - 1, new_used))
        return true;
      else if (dfs(nums, target, t, k, new_used))
        return true;
    }
    return false;
  }
};
