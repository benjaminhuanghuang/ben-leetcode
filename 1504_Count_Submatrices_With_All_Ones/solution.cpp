/*
1504. Count Submatrices With All Ones

Level: Medium

https://leetcode.com/problems/count-submatrices-with-all-ones
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
  Solution: Brute Force w/ Pruning

    Time complexity: O(m^2*n^2)
    Space complexity: O(1)
*/

class Solution
{
public:
  int numSubmat(vector<vector<int>> &mat)
  {

    const int R = mat.size();
    const int C = mat[0].size();
    // # of sub matrices with top-left at (sr, sc)
    auto subMats = [&](int sr, int sc) {
      int max_c = C;
      int count = 0;
      for (int r = sr; r < R; ++r)
        for (int c = sc; c < max_c; ++c)
          if (mat[r][c])
          {
            ++count;
          }
          else
          {
            max_c = c;
          }
      return count;
    };
    int ans = 0;
    for (int r = 0; r < R; ++r)
      for (int c = 0; c < C; ++c)
        ans += subMats(r, c);
    return ans;
  }
};