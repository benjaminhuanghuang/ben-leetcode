/*
986. Interval List Intersections

Level: Medium

https://leetcode.com/problems/interval-list-intersections
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
  vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
  {
    /*
      list of intervals is pairwise disjoint and in sorted order.
    */
    size_t i = 0;
    size_t j = 0;
    vector<vector<int>> ans;
    while (i < A.size() && j < B.size())
    {
      const int start = max(A[i][0], B[j][0]);
      const int end = min(A[i][1], B[j][1]);
      if (start <= end)
        ans.push_back({start, end});
      if (A[i][1] < B[j][1])
        ++i;
      else
        ++j;
    }
    return ans;
  }
};