/*
812. Largest Triangle Area

Level: Easy

https://leetcode.com/problems/largest-triangle-area
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
  Solution: Brute Force
    Time complexity: O(n^3)
    Space complexity: O(1)
*/

class Solution
{
public:
  double largestTriangleArea(vector<vector<int>> &points)
  {
    double maxArea = 0;
    for (int i = 0; i < points.size(); i++)
    {
      for (int j = 0; j < points.size(); j++)
      {
        if (i == j)
          continue;
        for (int k = j + 1; k < points.size(); k++)
        {
          if (k == i || k == j)
            continue;
          double tmp = area(points[i], points[j], points[k]);
          maxArea = maxArea < tmp ? tmp : maxArea;
        }
      }
    }
    return maxArea;
  }

private:
  double area(const vector<int> &x, const vector<int> &y, const vector<int> &z)
  {
    return 0.5 * (x[0] * y[1] + y[0] * z[1] + z[0] * x[1] - x[0] * z[1] - y[0] * x[1] - z[0] * y[1]);
  }
};