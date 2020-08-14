/*
1131. Maximum of Absolute Value Expression

Level: Medium

https://leetcode.com/problems/maximum-of-absolute-value-expression
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
  int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2)
  {
    int n = arr1.size();
    vector<vector<int>> v(4, vector<int>(n));
    vector<int> minnum(4, INT_MAX);
    vector<int> maxnum(4, INT_MIN);
    for (int i = 0; i < n; i++)
    {
      v[0][i] = arr1[i] + arr2[i] + i;
      v[1][i] = arr1[i] - arr2[i] + i;
      v[2][i] = -arr1[i] + arr2[i] + i;
      v[3][i] = -arr1[i] - arr2[i] + i;

      for (int j = 0; j < 4; j++)
      {
        minnum[j] = min(minnum[j], v[j][i]);
        maxnum[j] = max(maxnum[j], v[j][i]);
      }
    }
    int res = INT_MIN;
    for (int i = 0; i < 4; i++)
    {
      res = max(maxnum[i] - minnum[i], res);
    }
    return res;
  }
};