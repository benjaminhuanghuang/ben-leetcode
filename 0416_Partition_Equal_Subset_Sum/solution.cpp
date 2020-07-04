/*
416. Partition Equal Subset Sum

Level: Medium

https://leetcode.com/problems/partition-equal-subset-sum
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <numeric>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 

  http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-416-partition-equal-subset-sum/
*/

class Solution
{
public:
  /*
        O(2^n)
    */
  bool canPartition_bruteforece(vector<int> &nums)
  {
  }
  /*

    */
  bool canPartition(vector<int> &nums)
  {
    const int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
      return false;
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (const int num : nums)
    {
      for (int i = sum; i >= 0; --i)
        if (dp[i])
          dp[i + num] = 1;
      if (dp[sum / 2])
        return true;
    }
    return false;
  }
};