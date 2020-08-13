/*
1376. Time Needed to Inform All Employees

Level: Medium

https://leetcode.com/problems/time-needed-to-inform-all-employees
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
  Solution: Build the graph + DFS

    Time complexity: O(n)
    Space complexity: O(n)
*/

class Solution
{
public:
  int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
  {
    vector<vector<int>> es(n);
    for (int i = 0; i < n; ++i)
      if (i != headID)
        es[manager[i]].push_back(i);

    function<int(int)> dfs = [&](int cur) {
      int t = 0;
      for (int e : es[cur])
        t = max(t, dfs(e));
      return t + informTime[cur];
    };

    return dfs(headID);
  }
};