/*
1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows

Level: Hard

https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows
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
*/

class Solution
{
public:
  int kthSmallest(vector<vector<int>> &mat, int k)
  {
    const int m = mat.size();
    const int n = mat[0].size();
    priority_queue<vector<int>> q;
    vector<int> node(m + 1); // {-sum, idx_0, idx_1, ..., idx_m}
    for (int i = 0; i < m; ++i)
      node[0] -= mat[i][0];
    q.push(node);
    set<vector<int>> seen{{node}};
    while (!q.empty())
    {
      const vector<int> cur = q.top();
      q.pop();
      if (--k == 0)
        return -cur[0];
      for (int i = 1; i <= m; ++i)
      {
        if (cur[i] == n - 1)
          continue;
        vector<int> nxt(cur);
        ++nxt[i]; // increase i-th row's index.
        // Update sum.
        nxt[0] -= (mat[i - 1][nxt[i]] - mat[i - 1][nxt[i] - 1]);
        if (!seen.insert(nxt).second)
          continue;
        q.push(move(nxt));
      }
    }
    return -1;
  }
};