/*
7. Reverse Integer
https://leetcode.com/problems/reverse-integer/
*/
#include <limits>

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
    if (n > std::numeric_limits<int>::max())
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
    if (x < 0)
    {
      x = 0 - x;
      flag = true;
    }

    int res = 0;
    int p = x;

    while (p > 0)
    {
      int mod = p % 10;
      p = p / 10;
      res = res * 10 + mod;   // overflow
    }

    if (flag)
    {
      res = 0 - res;
    }

    return res;
  }
};