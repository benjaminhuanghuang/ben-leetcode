/*
801. Minimum Swaps To Make Sequences Increasing

Level: Medium

https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing
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
  Solution: DP
*/

class Solution
{
public:
  int minSwap(vector<int> &A, vector<int> &B)
  {
    const int n = A.size();

    vector<int> keep(n, INT_MAX);
    vector<int> swap(n, INT_MAX);

    keep[0] = 0;
    swap[0] = 1;

    for (int i = 1; i < n; ++i)
    {
      if (A[i] > A[i - 1] && B[i] > B[i - 1])
      {
        // Good case, no swapping needed.
        keep[i] = keep[i - 1];

        // Swapped A[i - 1] / B[i - 1], swap A[i], B[i] as well
        swap[i] = swap[i - 1] + 1;
      }

      if (B[i] > A[i - 1] && A[i] > B[i - 1])
      {
        // A[i - 1] / B[i - 1] weren't swapped.
        swap[i] = min(swap[i], keep[i - 1] + 1);

        // Swapped A[i - 1] / B[i - 1], no swap needed for A[i] / B[i]
        keep[i] = min(keep[i], swap[i - 1]);
      }
    }

    return min(keep.back(), swap.back());
  }
};

/*
  DFS
*/
class Solution {
public:
  int minSwap(vector<int>& A, vector<int>& B) {
    int ans = INT_MAX;
    dfs(A, B, 0, 0, ans);
    return ans;
  }
private:
  void dfs(vector<int>& A, vector<int>& B, int i, int c, int& ans) {
    if (c >= ans) return;
    
    if (i == A.size()) {
      ans = min(ans, c);
      return;
    }
    
    if (i == 0 || A[i] > A[i - 1] && B[i] > B[i - 1])
      dfs(A, B, i + 1, c, ans);
    
    if (i == 0 || A[i] > B[i - 1] && B[i] > A[i - 1]) {
      swap(A[i], B[i]);
      dfs(A, B, i + 1, c + 1, ans);
      swap(A[i], B[i]);
    }
  }
};