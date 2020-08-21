/*
850. Rectangle Area II

Level: Hard

https://leetcode.com/problems/rectangle-area-ii
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
  https://www.cnblogs.com/grandyang/p/11371256.html
*/

class Solution
{
public:
  int rectangleArea(vector<vector<int>> &rectangles)
  {
    long res = 0, M = 1e9 + 7;
    vector<vector<int>> all;
    for (auto rectangle : rectangles)
    {
      helper(all, rectangle, 0);
    }
    for (auto &a : all)
    {
      res = (res + (long)(a[2] - a[0]) * (long)(a[3] - a[1])) % M;
    }
    return res;
  }
  void helper(vector<vector<int>> &all, vector<int> cur, int start)
  {
    if (start >= all.size())
    {
      all.push_back(cur);
      return;
    }
    auto rec = all[start];
    if (cur[2] <= rec[0] || cur[3] <= rec[1] || cur[0] >= rec[2] || cur[1] >= rec[3])
    {
      helper(all, cur, start + 1);
      return;
    }
    if (cur[0] < rec[0])
    {
      helper(all, {cur[0], cur[1], rec[0], cur[3]}, start + 1);
    }
    if (cur[2] > rec[2])
    {
      helper(all, {rec[2], cur[1], cur[2], cur[3]}, start + 1);
    }
    if (cur[1] < rec[1])
    {
      helper(all, {max(rec[0], cur[0]), cur[1], min(rec[2], cur[2]), rec[1]}, start + 1);
    }
    if (cur[3] > rec[3])
    {
      helper(all, {max(rec[0], cur[0]), rec[3], min(rec[2], cur[2]), cur[3]}, start + 1);
    }
  }
};