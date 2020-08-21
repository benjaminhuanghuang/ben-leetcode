/*
440. K-th Smallest in Lexicographical Order

Level: Hard

https://leetcode.com/problems/k-th-smallest-in-lexicographical-order
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
  https://www.cnblogs.com/grandyang/p/6031787.html
*/

class Solution
{
public:
  int findKthNumber(int n, int k)
  {
    int cur = 1;
    --k;
    while (k > 0)
    {
      long long step = 0, first = cur, last = cur + 1;
      while (first <= n)
      {
        step += min((long long)n + 1, last) - first;
        first *= 10;
        last *= 10;
      }
      if (step <= k)
      {
        ++cur;
        k -= step;
      }
      else
      {
        cur *= 10;
        --k;
      }
    }
    return cur;
  }
};