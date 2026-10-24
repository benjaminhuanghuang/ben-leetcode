/*
149. Max Points on a Line

Level: Hard

https://leetcode.com/problems/max-points-on-a-line
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution:  count by slope
    用斜率作map的key。其中斜率要注意x = 0的情况，即将vertical的数单独计算。

  Time complexity: O(n^2)

  Space complexity: O(n)
*/

class Solution
{
public:
  int maxPoints(vector<vector<int>> &points)
  {
    int n = points.size();
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
      map<pair<int, int>, int> count;
      int same_points = 1;
      int max_points = 0;
      for (int j = i + 1; j < n; ++j)
      {
        const vector<int> &p1 = points[i];
        const vector<int> &p2 = points[j];
        if (p1[0] == p2[0] && p1[1] == p2[1])
          ++same_points;
        else
          max_points = max(max_points, ++count[getSlope(p1, p2)]);
      }
      ans = max(ans, same_points + max_points);
    }
    return ans;
  }

private:
  // slope dy/dx : <dy, dx>
  std::pair<int, int> getSlope(const vector<int> &p1, const vector<int> &p2)
  {
    const int dx = p2[0] - p1[0];
    const int dy = p2[1] - p1[1];

    // horizontal line
    if (dy == 0)
      return {p1[1], 0};
    // vertical line
    if (dx == 0)
      return {0, p1[0]};

    const int d = gcd(dx, dy);
    return {dy / d, dx / d};
  }

  int gcd(int m, int n)
  {
    return n == 0 ? m : gcd(n, m % n);
  }
};