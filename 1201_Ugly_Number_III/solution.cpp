/*
1201. Ugly Number III

Level: Medium

https://leetcode.com/problems/ugly-number-iii
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
  https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-1201-ugly-number-iii/
*/

class Solution
{
public:
  int nthUglyNumber(int n, long a, long b, long c)
  {
    long l = 1;
    long r = INT_MAX;
    long ab = lcm(a, b);
    long ac = lcm(a, c);
    long bc = lcm(b, c);
    long abc = lcm(a, bc);
    while (l < r)
    {
      long m = l + (r - l) / 2;
      long k = m / a + m / b + m / c - m / ab - m / ac - m / bc + m / abc;
      if (k >= n)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};