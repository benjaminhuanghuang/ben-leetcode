/*
66. Plus One

https://leetcode.com/problems/plus-one/
*/
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> plusOne(vector<int> &digits)
  {
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; --i)
    {
      digits[i] += carry;
      carry = digits[i] / 10;
      digits[i] %= 10;
    }
    if (carry)
      digits.insert(begin(digits), carry);
    return digits;
  }
};

class Solution_Better
{
public:
  vector<int> plusOne(vector<int> &digits)
  {
    for (int i = digits.size() - 1; i >= 0; --i)
    {
      if (digits[i] < 9)
      {
        digits[i]++;
        return digits;
      }
      digits[i] = 0; // set digits[i] to 0 if it is 9
    }
    digits.insert(begin(digits), 1);
    return digits;
  }
};