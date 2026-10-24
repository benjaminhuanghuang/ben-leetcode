/*
6. ZigZag Conversion
https://leetcode.com/problems/zigzag-conversion/
*/
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  string convert(string s, int nRows)
  {
    if (nRows == 1)
      return s;

    vector<string> ss(nRows);
    int len = s.length();
    int x = 0, y = 0, i = 0;
    bool down = true;
    while (i < len)
    {
      // put s[i] to row
      ss[y] += s[i];
      // adjust the y
      if (down)
      {
        ++y;
        if (y == nRows)
        {
          down = false;
          y -= 2;
        }
      }
      else
      {
        --y;
        if (y < 0)
        {
          down = true;
          y = 1;
        }
      }
      i++;
    }

    string ans;
    for (const string &r : ss)
      ans += r;
    return ans;
  }
};