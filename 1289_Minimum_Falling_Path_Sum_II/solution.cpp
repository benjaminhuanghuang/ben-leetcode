/*
1289. Minimum Falling Path Sum II

Level: Hard

https://leetcode.com/problems/minimum-falling-path-sum-ii
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
  Solution:  DP
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1289-minimum-falling-path-sum-ii/

*/

class Solution
{
public:
  int minFallingPathSum(vector<vector<int>> &arr)
  {
    constexpr int kInf = 1e6;
    for (int i = 1; i < arr.size(); ++i)
      for (int j = 0; j < arr[0].size(); ++j)
      {
        int m = kInf;
        for (int k = 0; k < arr[0].size(); ++k)
        {
          if (k == j)
            continue;
          m = min(m, arr[i - 1][k]);
        }
        arr[i][j] += m;
      }
    return *min_element(begin(arr.back()), end(arr.back()));
  }
};