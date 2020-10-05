/*
7. Reverse Integer
https://leetcode.com/problems/reverse-integer/
*/
#include <climits>

class Solution_overflow
{
public:
  int reverse(int x)
  {
    long k = x;
    bool isNegative = x < 0;
    if (isNegative)
    {
      k = -k; // overflow -2147483648
    }

    long n = 0;
    while (k > 0)
    {
      int digit = k % 10;
      n = n * 10 + digit; // overflow when x = 1534236469
      k = k / 10;
    }
    if (n > INT_MAX)
      return 0;
    if (isNegative)
      n = -n;

    return n;
  }
};

class Solution
{
public:
  int reverse(int x)
  {
    int rev = 0;
    while (x != 0)
    {
      rev = rev * 10 + x % 10; // overflow!
      x = x / 10;
    }

    return rev;
  }
};

class Solution
{
public:
  int reverse(int x)
  {
    //flag marks if x is negative
    bool flag = false;
    long val = x;
    if (val < 0)
    {
      val = -val;              // overflow
      flag = true;
    }

    long res = 0;
  
    while (val > 0)
    {
      int digit = val % 10;
      val = val / 10;
      res = res * 10 + digit;   // overflow
    }

    if(res > INT_MAX){
      res = 0;
    }
    if (flag)
    {
      res = 0 - res;
    }

    return res;
  }
};