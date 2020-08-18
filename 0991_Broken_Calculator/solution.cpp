/*
991. Broken Calculator

Level: Medium

https://leetcode.com/problems/broken-calculator
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
  https://buptwc.com/2019/02/10/Leetcode-991-Broken-Calculator/
  
  Solution: 
  https://zxi.mytechroad.com/blog/greedy/leetcode-991-broken-calculator/

  Thinking backwards, making Y <= X by adding 1 or dividing 2.

  If Y is even, (Y + 1) // 2 == Y // 2, there is no need to do the extra step
  If Y is odd (Y + 1) // 2 = (Y // 2) + 1, so only do + 1 when Y is odd

  Time complexity: O(log(Y-X))
  Space complexity: O(1)
*/

class Solution
{
public:
  int brokenCalc(int X, int Y)
  {
    if (X >= Y)
      return X - Y;
    return 1 + brokenCalc(X, Y % 2 ? Y + 1 : Y / 2);
  }
};