/*
367. Valid Perfect Square

Level: Easy

https://leetcode.com/problems/valid-perfect-square
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
  bool isPerfectSquare(int num)
  {
    if (num < 1)
      return false;
    if (num == 1)
      return true;

    int left = 0;
    int right = num / 2;
    while (left <= right)
    {
      int mid = left + ((right - left) >> 1);
      long val = (long)mid * mid;  // mid * mid can be a large number
      if (val == num)
        return true;
      else if (val > num)
        right = mid - 1;
      else
        left = mid + 1;
    }
    return false;
  }
};