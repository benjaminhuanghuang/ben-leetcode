/*
1105. Filling Bookcase Shelves

Level: Medium

https://leetcode.com/problems/filling-bookcase-shelves
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
  https://www.youtube.com/watch?v=a7TLEVdqg0Q
*/

class Solution
{
public:
  int minHeightShelves(vector<vector<int>> &books, int shelf_width)
  {
    int n = books.size();
    vector<int> dp(n, INT_MAX / 2);
    for (int j = 0; j < n; j++)
    {
      int w = 0, h = 0;
      for (int i = j; i >= 0; i--)
      {
        if ((w += books[i][0]) > shelf_width)
          break;
        h = max(h, books[i][1]);
        dp[j] = min(dp[j], (i == 0 ? 0 : dp[i - 1]) + h);
      }
    }
    return dp.back();
  }
};