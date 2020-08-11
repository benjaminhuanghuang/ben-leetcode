/*
1437. Check If All 1's Are at Least Length K Places Away

Level: Medium

https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away
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
  https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1437-check-if-all-1s-are-at-least-length-k-places-away/
*/

class Solution
{
public:
  bool kLengthApart(vector<int> &nums, int k)
  {
    int d = k + 1; // distant enough
    for (int n : nums)
    {
      if (n == 0)
      {
        ++d;
      }
      else
      {
        if (d < k)
          return false;
        d = 0;
      }
    }
    return true;
  }
};