/*
1021. Remove Outermost Parentheses [Easy]

https://leetcode.com/problems/remove-outermost-parentheses/
*/
#include <string>
#include <stack>
using namespace std;

/*
  Track # of opened parentheses
*/
class Solution
{
public:
  string removeOuterParentheses_naive(string S)
  {
    if (S.length() == 0)
    {
      return "";
    }
    string ans;
    string rep;
    stack<char> s;
    for (char c : S)
    {
      if (s.empty())
      {
        s.push(c);
      }
      else
      {
        if (s.top() == '(' && c == '(')
        {
          s.push(c);
          rep += c;
        }
        else if (s.top() == '(' && c == ')')
        {
          s.pop();
          if (s.empty())
          {
            ans += rep;
            rep = "";
          }
          else
          {
            rep += c;
          }
        }
      }
    }
    return ans;
  }

  string removeOuterParentheses_huahua(string S)
  {
    string ans;
    // the # of opened parentheses after current char
    int n = 0;
    for (char c : S)
    {
      // keep '(' if n > 1 and keep ')' if n > 0
      if (c == '(' && n++)
        ans += c;
      if (c == ')' && --n)
        ans += c;
    }
    return ans;
  }

  //https://www.youtube.com/watch?v=e1yJ40MdF50
  string removeOuterParentheses_xingxing(string S)
  {
    string ans;
    // the # of opened parentheses after current char
    int opened = 0;
    for (char c : S)
    {
      if (c == '(')
      {
        opened++;
        if (opened != 1)
          ans += c;
      }
      if (c == ')')
      {
        opened--;
        if (opened != 0)
          ans += c;
      }
    }
    return ans;
  }
};