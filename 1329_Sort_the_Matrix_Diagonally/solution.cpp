/*
1329. Sort the Matrix Diagonally

Level: Medium

https://leetcode.com/problems/sort-the-matrix-diagonally
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
  https://zxi.mytechroad.com/blog/hashtable/leetcode-1329-sort-the-matrix-diagonally/
*/

class Solution
{
public:
  vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
  {
    const int m = mat.size();
    const int n = mat[0].size();
    vector<deque<int>> qs(m + n);

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        qs[i - j + n].push_back(mat[i][j]);
    
    for (auto &q : qs)
      sort(begin(q), end(q));
    
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
      {
        mat[i][j] = qs[i - j + n].front();
        qs[i - j + n].pop_front();
      }
    return mat;
  }
};