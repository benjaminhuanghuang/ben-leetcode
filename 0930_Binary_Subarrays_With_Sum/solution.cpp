/*
930. Binary Subarrays With Sum

Level: Medium

https://leetcode.com/problems/binary-subarrays-with-sum
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
  Solution: Prefix Sum

    counts[s] := # of subarrays start from 0 that have sum of s
    ans += counts[s – S] if s >= S

    Time complexity: O(n)
    Space complexity: O(n)
*/

class Solution
{
public:
  int numSubarraysWithSum(vector<int> &A, int S)
  {
    const int n = A.size();
    vector<int> counts(n + 1);
    counts[0] = 1;
    int ans = 0;
    int sum = 0;
    for (int a : A)
    {
      sum += a;
      if (sum >= S)
        ans += counts[sum - S];
      ++counts[sum]; // # of subarrays start from 0 that have sum of s
    }
    return ans;
  }
};