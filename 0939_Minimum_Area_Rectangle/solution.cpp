/*
939. Minimum Area Rectangle

Level: Medium

https://leetcode.com/problems/minimum-area-rectangle
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
  Try all pairs of points to form a diagonal and see whether pointers of another diagonal exist or not.
*/

class Solution
{
public:
  int minAreaRect(vector<vector<int>> &points)
  {
    unordered_map<int, unordered_set<int>> s;
    for (const auto &point : points)
      s[point[0]].insert(point[1]);

    const int n = points.size();
    int min_area = INT_MAX;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
      {
        int x0 = points[i][0];
        int y0 = points[i][1];
        int x1 = points[j][0];
        int y1 = points[j][1];
        if (x0 == x1 || y0 == y1)
          continue;
        if (s[x1].count(y0) && s[x0].count(y1))
        {
          // find rectangle
          int area = abs(x0 - x1) * abs(y0 - y1);
          min_area = min(area, min_area);
        }
      }
    return min_area == INT_MAX ? 0 : min_area;
  }
};