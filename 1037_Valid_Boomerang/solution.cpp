/*
1037. Valid Boomerang [Easy]

https://leetcode.com/problems/valid-boomerang/
*/

#include <vector>
#include <string>

using namespace std;

/*
*/

class Solution
{
public:
  bool isBoomerang(vector<vector<int>> &points)
  {
    if (points[0] == points[1] ||
        points[1] == points[2] ||
        points[0] == points[2])
      return false;

    int dx0 = points[0][0] - points[1][0];
    int dy0 = points[0][1] - points[1][1];
    int dx1 = points[0][0] - points[2][0];
    int dy1 = points[0][1] - points[2][1];
    // return dy0 / dx0 != dy1 / dx1;
    return dy0 * dx1 != dy1 * dx0; // Don't use division, because dx can be 0
  }
};