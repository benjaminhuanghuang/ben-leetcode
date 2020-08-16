/*
1404. Number of Steps to Reduce a Number in Binary Representation to One

Level: Medium

https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one
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

class Solution
{
public:
  int numSteps(string s)
  {
    if(s == "1")
      return 0;
    if(s[s.size()-1] == '0')
    {
      // if s is even, divide it by 2. which means remove the '0' at the end.
      return 1 + numSteps(s.substr(0, s.size()-1));
    }
    else
    {
      // if s is odd, add 1 to it. if the bit is 1, 1 + 1 => 0. if the bit is 0, 0 + 1 => 1
      int i = s.length() - 1;
      while (i >= 0)
      {
        if(s[i] == '0')  // if bit it 0 , change it to 1 and stop
        {
          s[i] = '1';
          break;
        }
        else
        {
          s[i] = '0';  // if bit it 1 , change it to 1 and continue
          i--;
        }
      }
      if(i==-1)       // means all bits in s is 1
      {
        s = '1' + s;
      }
      return 1+  numSteps(s);
    }
  }
};


/*
  Solution: 
  1 <= s.length <= 500 , can not conver it to nubmer
*/

class Solution
{
public:
  int numSteps(string s)
  {
    int ans = 0;
    int carry = 0;
    // The highest bit must be 1,
    // process to the 2nd highest bit (using i > 0)
    for (int i = s.length() - 1; i > 0; --i)
    {
      if (s[i] - '0' + carry == 1)
      {
        ans += 2;  // odd: +1, even: / 2
        carry = 1; // always has a carry
      }
      else
      {
        ans += 1; // even: / 2
        // carray remains e.g. 1 + 1 = 10, or 0 + 0 = 00
      }
    }
    // If there is a carry, then it's even, one more step.
    return ans + carry;
  }
};