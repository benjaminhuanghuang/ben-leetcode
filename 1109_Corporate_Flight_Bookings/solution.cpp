/*
1109. Corporate Flight Bookings

Level: Medium

https://leetcode.com/problems/corporate-flight-bookings
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
  vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
  {
    vector<int> ans(n + 1);
    for (const auto &b : bookings)
    {
      ans[b[0] - 1] += b[2];
      ans[b[1]] -= b[2];
    }
    for (int i = 1; i < n; ++i)
      ans[i] += ans[i - 1];
    ans.pop_back();
    return ans;
  }
};