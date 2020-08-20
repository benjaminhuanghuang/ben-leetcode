/*
233. Number of Digit One

Level: Hard

https://leetcode.com/problems/number-of-digit-one
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
  https://www.cnblogs.com/grandyang/p/4629032.html
*/

class Solution
{
public:
  int countDigitOne(int n)
  {
    long res = 0, a = 1, b = 1;
    while (n > 0)
    {
      res += (n + 8) / 10 * a + (n % 10 == 1) * b;
      b += n % 10 * a;
      a *= 10;
      n /= 10;
    }
    return res;
  }
};