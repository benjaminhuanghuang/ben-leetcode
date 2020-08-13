/*
1247. Minimum Swaps to Make Strings Equal

Level: Medium

https://leetcode.com/problems/minimum-swaps-to-make-strings-equal
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
  https://zxi.mytechroad.com/blog/math/leetcode-1247-minimum-swaps-to-make-strings-equal/
  
  Solution: 
  if s1[i] == s2[i] than no need to swap, so we can only look for
    case1. s1[i] = x, s2[i] = y, xy
    case2. s1[i] = y, s2[i] = x, yx

  If case1 + case2 is odd, then there’s no solution.

  Otherwise we can use one swap to fix two xys (or two yxs)
  xx, yy => xy, yx

  One special case is there an extra xy and and extra yx, which takes two swaps
  xy, yx => yy, xx => xy, xy

  Finally,
  ans = (case1 + 1) / 2 + (case2 + 1) / 2

  Time complexity: O(n)
  Space complexity: O(1)
*/

class Solution
{
public:
  int minimumSwap(string s1, string s2)
  {
    int xy = 0;
    int yx = 0;
    for (int i = 0; i < s1.length(); ++i)
    {
      if (s1[i] == 'x' && s2[i] == 'y')
        ++xy;
      if (s1[i] == 'y' && s2[i] == 'x')
        ++yx;
    }
    if ((xy + yx) % 2)
      return -1;
    return (xy + 1) / 2 + (yx + 1) / 2;
  }
};