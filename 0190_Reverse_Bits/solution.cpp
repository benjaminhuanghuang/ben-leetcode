/*
190. Reverse Bits
Reverse bits of a given 32 bits unsigned integer.

https://leetcode.com/problems/reverse-bits/

*/
#include <vector>

using namespace std;

class Solution
{
public:
  uint32_t reverseBits(uint32_t n)
  {
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++)
    {
      int digit = n & 1;
      ans = (ans << 1) | digit;
      n = n >> 1;
    }
    return ans;
  }

  uint32_t reverseBits_v2(uint32_t n)
  {
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++)
    {
      ans = (ans << 1) | (ans >> i & 1);
    }
    return ans;
  }
};