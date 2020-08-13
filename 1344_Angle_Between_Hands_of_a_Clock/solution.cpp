/*
1344. Angle Between Hands of a Clock

Level: Medium

https://leetcode.com/problems/angle-between-hands-of-a-clock
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
*/

class Solution
{
public:
  double angleClock(int hour, int minutes)
  {
    double a_m = minutes * 360 / 60;
    double a_h = (hour + minutes / 60.0) * 360 / 12;
    return min(abs(a_m - a_h), 360 - abs(a_m - a_h));
  }
};