/*
1401. Circle and Rectangle Overlapping

Level: Medium

https://leetcode.com/problems/circle-and-rectangle-overlapping
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
  Find the shortest distance from the center to the rectangle, return dist <= radius.
*/

class Solution
{
public:
  bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2)
  {
    int dx = x_center - max(x1, min(x2, x_center));
    int dy = y_center - max(y1, min(y2, y_center));
    return dx * dx + dy * dy <= radius * radius;
  }
};