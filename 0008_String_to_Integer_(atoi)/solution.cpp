/*
8. String to Integer (atoi)

https://leetcode.com/problems/string-to-integer-atoi/
*/
#include <string>
#include <climits>

using namespace std;

class Solution
{
public:
  int myAtoi(string str)
  {
    long long ans = 0;
    int neg = 0;  // how many "-"
    int pos = 0;  // how many "+" 
    bool p = false; // has '.'
    bool a = false; // has letters
    bool n = false; // has number
    for (int i = 0; i < str.length(); ++i)
    {
      if (str[i] == ' ')
      {
        // trim
        if (n || neg || pos)
          break;
      }
      else if (str[i] == '-')
      {
        if (n)
          break;
        else
          neg++;
      }
      else if (str[i] == '+')
      {
        if (n)
          break;
        else
          pos++;
      }
      else if (str[i] == '.')
        p = true;
      else if (str[i] >= '0' && str[i] <= '9' && !p && !a)
      {
        ans = ans * 10 + (str[i] - '0');
        n = true;
      }
      else
      {
        a = true;
      }
      if (ans / 10 > INT_MAX)
        break; // ans can be > 64 bit
    }

    if (neg)
      ans = -ans;

    if (ans > INT_MAX)
      ans = INT_MAX;
    if (ans < INT_MIN)
      ans = INT_MIN;

    if (pos + neg > 1)
      ans = 0;

    return ans;
  }
};