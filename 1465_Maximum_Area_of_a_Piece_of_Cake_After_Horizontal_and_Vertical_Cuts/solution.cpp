/*
1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts

Level: Medium

https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts
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
  https://zxi.mytechroad.com/blog/geometry/leetcode-1465-maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
  Find the max gap between vertical cuts mx and max gap between horizontal cuts my. ans = mx * my

*/

class Solution
{
public:
  int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
  {
    constexpr int kMod = 1e9 + 7;
    sort(begin(verticalCuts), end(verticalCuts));
    sort(begin(horizontalCuts), end(horizontalCuts));
    int mx = max(verticalCuts[0], w - verticalCuts.back());
    int my = max(horizontalCuts[0], h - horizontalCuts.back());
    for (int i = 1; i < verticalCuts.size(); ++i)
      mx = max(mx, verticalCuts[i] - verticalCuts[i - 1]);
    for (int i = 1; i < horizontalCuts.size(); ++i)
      my = max(my, horizontalCuts[i] - horizontalCuts[i - 1]);
    return static_cast<long>(mx) * my % kMod;
  }
};