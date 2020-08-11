/*
1318. Minimum Flips to Make a OR b Equal to c

Level: Medium

https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c
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
*/

class Solution
{
public:
  int minFlips(int a, int b, int c)
  {
    int count = 0;
    for (int i = 0; i < 32; ++i)
    {
      if (c & 1)
        count += 1 - ((a | b) & 1);
      else
        count += (a & 1) + (b & 1);
      a >>= 1;
      b >>= 1;
      c >>= 1;
    }
    return count;
  }
};