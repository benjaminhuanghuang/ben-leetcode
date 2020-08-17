/*
845. Longest Mountain in Array

Level: Medium

https://leetcode.com/problems/longest-mountain-in-array
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
  int longestMountain(vector<int> &A)
  {
    vector<int> inc(A.size());
    vector<int> dec(A.size());
    for (int i = 1; i < A.size(); ++i)
      if (A[i] > A[i - 1])
        inc[i] = inc[i - 1] + 1;
    for (int i = A.size() - 2; i > 0; --i)
      if (A[i] > A[i + 1])
        dec[i] = dec[i + 1] + 1;
    int ans = 0;
    for (int i = 0; i < A.size(); ++i)
      if (inc[i] && dec[i])
        ans = max(ans, inc[i] + dec[i] + 1);
    return ans >= 3 ? ans : 0;
  }
};