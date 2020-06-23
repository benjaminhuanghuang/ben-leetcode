/*
441. Arranging Coins

Level: Easy

https://leetcode.com/problems/arranging-coins
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

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
  int arrangeCoins(int n)
  {
    int l = 1;
    int r = n;
    while (l <= r)
    {
      int m = l + (r - l) / 2;
      long total = (long)m * (m + 1) / 2;
      if (total == n)
      {
        return m; //retrun biggest num <= target
      }
      else if (total >= n)
      {
        r = m - 1;
      }
      else
      {
        l = m + 1;
      }
    }
    return r; //retrun biggest num <= target
  }

  // x(x+1)/2 = n
  // x = sqrt(2 * n + 1/4) - 1/2
  int ArrangeCoins_2(int n)
  {
    return (int)(sqrt(2 * (long)n + 0.25) - 0.5);
  }
};