/*
69. Sqrt(x)

Level: Easy

https://leetcode.com/problems/sqrtx
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
  int mySqrt(int x)
  {
    int res = 0;
    int low = 1;
    int high = x;

    while (low <= high)
    {
      int mid = (high - low) / 2 + low;

      if (mid == x / mid)
      {
        res = mid;
        break;
      }
      else if (mid < x / mid) // mid * mid < x,  mid is too small, check the bigger section
      {
        // DO NOT use (mid * mid < x) , when x is very big
        res = mid; // importent! for x = 2
        low = mid + 1;
      }
      else
      {
        // mid is too big, check the smaller section
        high = mid - 1;
      }
    }
    return res;
  }

  /*
    lower bound
  */
  int mySqrt_v2(int x)
  {
    if (x < 0)
      return -1;
    if (x == 0)
      return 0;
    int l = 1, r = x;

    while (l <= r)
    {
      int mid = l + (r - l) / 2;
      if (mid > x / mid)
        r = mid - 1;
      else
        l = mid + 1;
    }

    return r;
  }
};