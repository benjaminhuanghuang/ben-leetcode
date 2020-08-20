/*
960. Delete Columns to Make Sorted III

Level: Hard

https://leetcode.com/problems/delete-columns-to-make-sorted-iii
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
  https://www.acwing.com/solution/LeetCode/content/685/
*/

class Solution
{
public:
  int minDeletionSize(vector<string> &A)
  {
    int n = A.size(), m = A[0].size();
    vector<int> f(m + 1, m);

    for (int i = 0; i < n; i++)
      A[i] = " " + A[i];

    int ans = m;
    f[0] = 0;
    for (int i = 1; i <= m; i++)
    {
      for (int j = i - 1; j >= 0; j--)
      {
        bool flag = true;
        for (int k = 0; k < n; k++)
          if (A[k][j] > A[k][i])
          {
            flag = false;
            break;
          }

        if (flag)
        {
          f[i] = min(f[i], f[j] + i - j - 1);
        }
      }
      ans = min(ans, f[i] + m - i);
    }
    return ans;
  }
};