/*
1536. Minimum Swaps to Arrange a Binary Grid

Level: Medium

https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid
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
  https://zxi.mytechroad.com/blog/uncategorized/leetcode-1536-minimum-swaps-to-arrange-a-binary-grid/
  
  Counting how many tailing zeros each row has.
  For i-th row, it needs n – i – 1 tailing zeros.
  We need to find the first row that has at least n – i – 1 tailing zeros and bubbling it up to the i-th row. 
  This process is very similar to bubble sort.
*/

class Solution
{
public:
  int minSwaps(vector<vector<int>> &grid)
  {
    const int n = grid.size();

    // count how many tailing zeros each row has.
    vector<int> zeros;
    for (const auto &row : grid)
    {
      int zero = 0;
      for (int i = n - 1; i >= 0 && row[i] == 0; --i)
        ++zero;
      zeros.push_back(zero);
    }

    int ans = 0;
    for (int i = 0; i < n - 1; ++i)
    {
      int j = i;
      int z = n - i - 1; // the i-th needs n - i - 1 zeros
      // Find first row with at least z tailing zeros.
      while (j < n && zeros[j] < z)
        ++j;
      if (j == n)
        return -1;
      while (j > i)
      {
        zeros[j] = zeros[j - 1];
        --j;
        ++ans;
      }
    }
    return ans;
  }
};