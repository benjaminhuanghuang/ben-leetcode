/*
1253. Reconstruct a 2-Row Binary Matrix

Level: Medium

https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix
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
  https://zxi.mytechroad.com/blog/greedy/leetcode-1253-reconstruct-a-2-row-binary-matrix/
  
*/

class Solution
{
public:
  vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum)
  {
    const int n = colsum.size();
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < n; ++i)
      if (colsum[i] == 2)
      {
        a[0][i] = a[1][i] = 1;
        --upper;
        --lower;
      }

    for (int i = 0; i < n; ++i)
      if (colsum[i] == 1)
        if (upper > lower)
        {
          a[0][i] = 1;
          --upper;
        }
        else
        {
          a[1][i] = 1;
          --lower;
        }
    if (upper != 0 || lower != 0)
      return {};
    return a;
  }
};
