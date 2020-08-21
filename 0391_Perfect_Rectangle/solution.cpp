/*
391. Perfect Rectangle

Level: Hard

https://leetcode.com/problems/perfect-rectangle
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 

  https://zxi.mytechroad.com/blog/geometry/leetcode-391-perfect-rectangle/


*/

class Solution
{
public:
  bool isRectangleCover(vector<vector<int>> &rectangles)
  {
    // sorted by x, then y, left-bottom to right-top
    set<pair<int, int>> corners;  // x:y
    int area = 0;
    for (const auto &rect : rectangles)
    {
      // 4 corners, left-bottom ...
      pair<int, int> p1{rect[0], rect[1]};
      pair<int, int> p2{rect[2], rect[1]};
      pair<int, int> p3{rect[2], rect[3]};
      pair<int, int> p4{rect[0], rect[3]};
      for (const auto &p : {p1, p2, p3, p4})
      {
        const auto &ret = corners.insert(p);  // return itrator:exist
        if (!ret.second)
          corners.erase(ret.first);
      }
      area += (p3.first - p1.first) * (p3.second - p1.second);
    }
    if (corners.size() != 4)
      return false;
    const auto &p1 = *begin(corners);    // left-bottom
    const auto &p3 = *rbegin(corners);   // right-top
    return area == (p3.first - p1.first) * (p3.second - p1.second);
  }
};