/*
844. Backspace String Compare

https://leetcode.com/problems/backspace-string-compare/
*/
#include <string>
using namespace std;

/*
using string as stack
*/
class Solution
{
public:
  bool backspaceCompare(string S, string T)
  {
    return type(S) == type(T);
  }

private:
  string type(string S)
  {
    string o;
    for (char c : S)
      if (c == '#')
      {
        if (!o.empty())
          o.pop_back();
      }
      else
      {
        o.push_back(c);
      }
    return o;
  }
};