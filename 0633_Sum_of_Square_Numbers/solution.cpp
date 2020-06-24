/*
633. Sum of Square Numbers

Level: Easy

https://leetcode.com/problems/sum-of-square-numbers
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

  a^2 + b^2 = c.
*/

class Solution
{
public:
  bool judgeSquareSum(int c)
  {
    for (int a = 0; a < (int)(sqrt(c) + 1); a++)
    {
      int squareOfb = c - a * a;
      int b = (int)sqrt(squareOfb);
      if (b * b == squareOfb)
        return true;
    }
    return false;
  }

  /*
    two points
  */
  bool judgeSquareSum_v2(int c)
  {
    if (c < 0)
      return false;

    int l = 0;
    int r = std::sqrt(c);
    while (l <= r)
    {
      long sum = (long)l * l + r * r;
      if (sum < c)
      {
        l++;
      }
      else if (sum > c)
      {
        r--;
      }
      else if (sum == c)
      {
        return true;
      }
    }
    return false;
  }
};