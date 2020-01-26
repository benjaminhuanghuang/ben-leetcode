/*
678. Valid Parenthesis String

https://leetcode.com/problems/valid-parenthesis-string/
*/

#include <string>

using namespace std;
/*
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-678-valid-parenthesis-string/
*/
class Solution
{
public:
  bool checkValidString(string s)
  {
    int min_op = 0;
    int max_op = 0;

    for (char c : s)
    {
      if (c == '(')
        ++min_op;
      else
        --min_op;
      if (c != ')')
        ++max_op;
      else
        --max_op;
      if (max_op < 0)
        return false;
      min_op = max(0, min_op);
    }

    return min_op == 0;
  }
};