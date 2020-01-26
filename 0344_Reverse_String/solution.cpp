/*
344. Reverse String

https://leetcode.com/problems/reverse-string/
*/

#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  void reverseString(vector<char> &s)
  {
    if (s.size() == 0)
      return;
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
      swap(s[l++], s[r--]);
    }
  }
};