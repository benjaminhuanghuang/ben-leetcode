/*
452. Minimum Number of Arrows to Burst Balloons

Level: Medium

https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons
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
  https://www.youtube.com/watch?v=DguJN47_mSg
  Time complexity: O(nlogn)

  Space complexity: O(1)
*/

class Solution
{
public:
  int findMinArrowShots(vector<vector<int>> &points)
  {
    if (points.empty())
      return 0;
    
    // Sort by end
    sort(points.begin(), points.end(),
         [&](const vector<int> &a, const vector<int> &b) {
           return a[1] < b[1];
         });

    // find all inverval which start < current_right     
    int right = points.front()[1];
    int ans = 1;
    for (const auto &point : points)
    {
      if (point[0] > right)
      {
        right = point[1];
        ++ans;
      }
    }
    return ans;
  }
};