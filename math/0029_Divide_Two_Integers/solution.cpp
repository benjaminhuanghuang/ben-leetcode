/*
29. Divide Two Integers

Level: Medium

https://leetcode.com/problems/divide-two-integers
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
#include <climits>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution 1: 
    Brute force:  keep using subtraction 

  Solution 2:
      divisor *= 2
      quotient *= 2

*/

class Solution
{
public:
  /*
    Be carefurl the input -2147483648, -1
  */
  int divide_wrong(int dividend, int divisor)
  {
    if (divisor == 0)
      return INT_MAX;
    bool isPositive = !((dividend > 0) ^ (divisor > 0));

    dividend = abs(dividend); //Error! abs(-2147483648) overflow
    divisor = abs(divisor);

    int result = 0;
    //
    while (dividend >= divisor)
    {
      int quotient = 1;
      int max_divisor = divisor;
      //用除数每次*2（向左移动一位）去逼近被除数，被除数减去新的除数如此循环。
      while ((max_divisor << 1) <= dividend)
      {
        max_divisor <<= 1;
        quotient <<= 1;
      }
      dividend -= max_divisor;
      result += quotient;
    }
    // Error when result is 2147483648, (int)2147483648 is -2147483647
    return isPositive ? min(INT_MAX, result) : max(INT_MIN, -result);
  }

  int divide(int dividend, int divisor)
  {
    if (divisor == 0)
      return INT_MAX;
    bool isPositive = !((dividend > 0) ^ (divisor > 0));

    long dividendL = abs((long)dividend); // abs(-2147483648) overflow
    long divisorL = abs((long)divisor);

    long result = 0; // result can be 2147483648
    //
    while (dividendL >= divisorL)
    {
      long cur = 1;
      long start = divisorL;
      //用除数每次*2（向左移动一位）去逼近被除数，被除数减去新的除数如此循环。
      while ((start << 1) <= dividendL)
      {
        start <<= 1;
        cur <<= 1;
      }
      dividendL -= start;
      result += cur;
    }

    if (isPositive)
    {
      //min(INT_MAX, (int)result) cause error
      if (result > INT_MAX)
        return INT_MAX;
      return result;
    }
    else
    {
      if (-result < INT_MIN)
        return INT_MIN;
      return -result;
    }
  }
};