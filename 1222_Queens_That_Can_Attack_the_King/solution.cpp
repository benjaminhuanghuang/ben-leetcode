/*
1222. Queens That Can Attack the King

Level: Medium

https://leetcode.com/problems/queens-that-can-attack-the-king
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  https://zxi.mytechroad.com/blog/simulation/leetcode-1222-queens-that-can-attack-the-king/
*/

class Solution
{
public:
  vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
  {
    vector<vector<int>> b(8, vector<int>(8));
    for (const auto &q : queens)
      b[q[0]][q[1]] = 1;
    vector<vector<int>> ans;
    for (const auto &q : queens)
    {
      for (int dx = -1; dx <= 1; ++dx)
        for (int dy = -1; dy <= 1; ++dy)
        {
          if (dx == 0 && dy == 0)
            continue;
          int x = q[1] + dx;
          int y = q[0] + dy;
          while (x >= 0 && y >= 0 && x < 8 && y < 8 && !b[y][x])
          {
            if (x == king[1] && y == king[0])
              ans.push_back(q);
            x += dx;
            y += dy;
          }
        }
    }
    return ans;
  }
};
/*
  Solution 2: HashTable + Binary Search
  Time complexity: O(nlogn)
  Space complexity: O(n)

  Support arbitrarily large boards, e.g. 1e9 x 1e9 with 1e6 # of queens.
*/
class Solution {
public:
  vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {    
    unordered_map<int, map<int, vector<int>>> rows, cols, diag1, diag2;    
    for (const auto& q : queens) {
      const int x = q[1];
      const int y = q[0];
      rows[y][x] = q;
      cols[x][y] = q;
      diag1[x + y][x] = q;
      diag2[x - y][x] = q;
    }
    
    const int x = king[1];
    const int y = king[0];
    vector<vector<int>> ans;
    find(rows, y, x, ans);
    find(cols, x, y, ans);
    find(diag1, x + y, x, ans);
    find(diag2, x - y, x, ans);
    return ans;
  }
private:
  void find(const unordered_map<int, map<int, vector<int>>>& m, int idx, int key, vector<vector<int>>& ans) {    
    if (!m.count(idx)) return;
    const auto& d = m.at(idx);
    auto it = d.upper_bound(key);
    if (it != end(d))
      ans.push_back(it->second);
    if (it != begin(d))
      ans.push_back(prev(it)->second);    
  }
};