/*
963. Minimum Area Rectangle II

https://leetcode.com/problems/minimum-area-rectangle-ii/
*/
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
/*
https://zxi.mytechroad.com/blog/geometry/leetcode-963-minimum-area-rectangle-ii/
*/

class Solution
{
  string getKey(int &x, int &y)
  {
    return to_string(x) + "_" + to_string(y);
  }

public:
  double minAreaFreeRect(vector<vector<int>> &points)
  {
    double ans = 0;
    unordered_map<string, int> f;
    for (auto it : points)
      f[getKey(it[0], it[1])] = 1;
    int n = points.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        for (int k = j + 1; k < n; k++)
        {
          int x1 = points[i][0], y1 = points[i][1];
          int x2 = points[j][0], y2 = points[j][1];
          int x3 = points[k][0], y3 = points[k][1];
          if (((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1)) != 0)
            continue;
          int x4 = x3 + x2 - x1, y4 = y3 + y2 - y1;
          if (f.count(getKey(x4, y4)) == 0)
            continue;
          double l = pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);
          double w = pow(pow(x3 - x1, 2) + pow(y3 - y1, 2), 0.5);
          double area = l * w;
          if (ans == 0)
            ans = area;
          else if (area < ans)
            ans = area;
        }
      }
    }
    return ans;
  }
};