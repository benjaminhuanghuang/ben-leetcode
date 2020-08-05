/*
1529. Bulb Switcher IV

Level: Medium

https://leetcode.com/problems/bulb-switcher-iv
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
  Flip from left to right, since flipping the a bulb won’t affect anything in the left.
  We count how many times flipped so far, and that % 2 will be the state for all the bulb to the right.
  If the current bulb’s state != target, we have to flip once.

  Time complexity: O(n)
  Space complexity: O(1)
*/

class Solution
{
public:
  int minFlips(string target)
  {
    int ans = 0;
    int cur = 0;
    for (char c : target)
    {
      if (c - '0' != cur)
      {
        cur ^= 1;
        ++ans;
      }
    }
    return ans;
  }
};