/*
1353. Maximum Number of Events That Can Be Attended

Level: Medium

https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended
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
  int maxEvents(vector<vector<int>> &events)
  {
    sort(begin(events), end(events), [](const auto &a, const auto &b) {
      return a[1] < b[1];
    });
    int ans = 0;
    unsigned char seen[100000 / 8 + 1] = {0};
    for (const auto &e : events)
    {
      for (int i = e[0]; i <= e[1]; ++i)
      {
        if (seen[i >> 3] & (1 << (i % 8)))
          continue;
        seen[i >> 3] |= 1 << (i % 8);
        ++ans;
        break;
      }
    }
    return ans;
  }
};