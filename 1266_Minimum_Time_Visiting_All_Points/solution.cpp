/*
1266. Minimum Time Visiting All Points

Level: Easy

https://leetcode.com/problems/minimum-time-visiting-all-points
*/
#include <vector>
#include <string>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  go diagonally first for min(dx, dy) steps, and then go straight line for abs(dx – dy) steps.

  Time complexity: O(n)
  Space complexity: O(1)
*/

class Solution
{
public:

  int minTimeToVisitAllPoints(vector<vector<int>> &points)
  {
    int ans = 0;
    for (int i = 1; i < points.size(); ++i)
    {
      int dx = abs(points[i - 1][0] - points[i][0]);
      int dy = abs(points[i - 1][1] - points[i][1]);
      // 
      ans += min(dx, dy) + abs(dx - dy);
    }
    return ans;
  }
};