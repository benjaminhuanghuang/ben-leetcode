/*
594. Longest Harmonious Subsequence

Level: Easy

https://leetcode.com/problems/longest-harmonious-subsequence
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
*/

class Solution
{
public:
  int findLHS(vector<int> &nums)
  {
    unordered_map<int, int> counter;
    for (int num : nums)
    {
      counter[num]++;
    }
    int longest = 0;
    for (auto kv : counter)
    {
      // 如果map包括num+1，那么比较longest with counter[num] + counter[num + 1]
      if (counter.count(kv.first + 1))
      {
        int tmp = counter[kv.first] + counter[kv.first + 1];
        longest = max(longest, tmp);
      }
    }
    return longest;
  }
};