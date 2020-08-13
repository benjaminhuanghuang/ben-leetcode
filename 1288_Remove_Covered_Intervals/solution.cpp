/*
1288. Remove Covered Intervals

Level: Medium

https://leetcode.com/problems/remove-covered-intervals
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
  int removeCoveredIntervals(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end(), [](vector<int> &v1, vector<int> &v2) {
      if (v1[0] < v2[0])
        return true;
      else if (v1[0] == v2[0])
      {
        if (v1[1] > v2[1])
          return true;
      }
      return false;
    });
    int x = intervals[0][0];
    int y = intervals[0][1];
    int ans = intervals.size();
    for (int i = 1; i < intervals.size(); i++)
    {
      if (intervals[i][0] >= x and intervals[i][1] <= y)
        ans--;
      else
      {
        x = intervals[i][0];
        y = intervals[i][1];
      }
    }
    return ans;
  }
};