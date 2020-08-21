/*
668. Kth Smallest Number in Multiplication Table

Level: Hard

https://leetcode.com/problems/kth-smallest-number-in-multiplication-table
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
  https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-668-kth-smallest-number-in-multiplication-table/
*/

class Solution
{
public:
  int findKthNumber(int m, int n, int k)
  {
    int l = 1;
    int r = m * n + 1;
    while (l < r)
    {
      int x = l + (r - l) / 2;
      if (LEX(m, n, x) >= k)
        r = x;
      else
        l = x + 1;
    }
    return l;
  }

private:
  // Returns # of elements in the m*n table that are <= x
  int LEX(int m, int n, int x)
  {
    int count = 0;
    for (int i = 1; i <= m; ++i)
      count += min(n, x / i);
    return count;
  }
};