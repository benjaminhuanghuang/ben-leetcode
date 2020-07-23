/*
477. Total Hamming Distance

Level: Medium

https://leetcode.com/problems/total-hamming-distance
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

  Brute force, compute Hamming Distance for all pairs. O(n^2) TLE

  Total distance += ones * zeros
  Count how many ones on i-th bit, assuming k. Distance += k * (n – k). O(32*n)
*/

class Solution
{
public:
  int totalHammingDistance(vector<int> &nums)
  {
    int ans = 0;
    unsigned int mask = 1;
    for (int i = 0; i < 32; ++i)
    {
      int count = 0;
      for (const int num : nums)
        if (num & mask)
          ++count;
      ans += (nums.size() - count) * count;
      mask <<= 1;
    }
    return ans;
  }
};