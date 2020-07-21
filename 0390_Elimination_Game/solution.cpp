/*
390. Elimination Game

Level: Medium

https://leetcode.com/problems/elimination-game
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
  int lastRemaining(int n)
  {
    int head = 1;
    int step = 1;
    bool left = true;

    while (n > 1)
    {
      if (left || n % 2 == 1)
      {
        head += step;
      }

      step *= 2;
      n /= 2;
      left = !left;
    }
    return head;
  }
};