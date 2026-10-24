/*
436. Find Right Interval

Level: Medium

https://leetcode.com/problems/find-right-interval
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
  vector<int> findRightInterval(vector<vector<int>> &intervals)
  {
    int n = intervals.size();
    unordered_map<int, int> original; // start: index
    for (int i = 0; i < n; i++)
    {
      original.emplace(intervals[i][0], i);
    }

    vector<int> res(n);

    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[0] < b[0];
    });

    for (int i = 0; i < n; i++)
    {
      int left = 0;
      int right = n - 1;
      // intervals[left][0] >= intervals[i][1]
      while (left < right)
      {
        int mid = left + (right - left) / 2;
        if (intervals[mid][0] >= intervals[i][1])
          right = mid;
        else
          left = mid + 1;
      }
      if (intervals[left][0] >= intervals[i][1] && left != i)
        res[original[intervals[i][0]]] = original[intervals[left][0]];
      else
        res[original[intervals[i][0]]] = -1;
    }

    return res;
  }
};