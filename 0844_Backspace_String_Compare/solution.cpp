/*
844. Backspace String Compare

https://leetcode.com/problems/backspace-string-compare/

给你2个字符串表示打字顺序，判断它们的结果是否相同，’#’表示退格键。

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