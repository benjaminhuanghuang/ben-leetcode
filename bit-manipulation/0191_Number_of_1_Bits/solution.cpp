/*
191. Number of 1 Bits

Level: Easy

https://leetcode.com/problems/number-of-1-bits
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
  int hammingWeight(uint32_t n)
  {
    int count;

    while (n > 0)
    {
      if (n & 1)
      {
        count++;
      }
      n = n >> 1;
    }
    return count;
  }

  int hammingWeight_v2(uint32_t n)
  {
    int count;

    for (int i =0 ; i< 32 ; i++)
    {
      if (n & (1 << i))
      {
        count++;
      }

    }
    return count;
  }
};