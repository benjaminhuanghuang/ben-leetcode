/*
693. Binary Number with Alternating Bits

Level: Easy

https://leetcode.com/problems/binary-number-with-alternating-bits
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
  bool hasAlternatingBits(int n)
  {
    int bit = -1;
    while (n > 0)
    {
      if ((n & 1) == 1)
      {
        if (bit == 1)
          return false;
        bit = 1;
      }
      else
      {
        if (bit == 0)
          return false;
        bit = 0;
      }
      n >>= 1;
    }
    return true;
  }
};