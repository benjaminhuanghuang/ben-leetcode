/*
1342. Number of Steps to Reduce a Number to Zero

Level: Easy

https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero
*/
#include <vector>
#include <string>
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
  int numberOfSteps(int num)
  {
    int steps = 0;
    while (num > 0)
    {
      if (num & 1) // odd
      {
        num -= 1;
      }
      else
      {
        num /= 2;
      }
      steps++;
    }
    return steps;
  }
};