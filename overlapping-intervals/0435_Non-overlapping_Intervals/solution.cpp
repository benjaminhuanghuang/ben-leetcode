/*
435. Non-overlapping Intervals

Level: Medium

https://leetcode.com/problems/non-overlapping-intervals
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
  int eraseOverlapIntervals(vector<vector<int>> &intervals)
  {
    // sort by end
    sort(intervals.begin(), intervals.end(), [](const vector<int> &x, const vector<int> &y) { return x[1] < y[1]; });

    int end = INT_MIN;
    //ans为可以两两互不相交的最大区间数
    int ans = 0;
    // 遍历排序后的区间，若当前区间的起点≥end，则更新end为当前区间的终点，并将计数器ans+1
    for (auto i : intervals)
    {
      // start of i > current end
      if (i[0] >= end)
      {
        end = i[1];
        ans++;
      }
    }

    return intervals.size() - ans;
  }
};