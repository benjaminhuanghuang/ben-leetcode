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
      long m = l + (r - l) / 2;
      if (m * (m + 1) / 2 > n)
        r = (int)m - 1;
      else
      {
        l = (int)m + 1;
      }
    }
    return l;
  }
};