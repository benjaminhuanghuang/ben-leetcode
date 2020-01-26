/*
20. Valid Parentheses

https://leetcode.com/problems/valid-parentheses/
*/

#include <string>
#include <unordered_map>
#include <stack>

using namespace std;
/*
  map + stack
*/
class Solution
{
public:
  bool isValid(string s)
  {
    unordered_map<char, char> p{{')', '('}, {']', '['}, {'}', '{'}};
    stack<char> st;
    for (char c : s)
    {
      if (!p.count(c))
      {
        st.push(c);
      }
      else
      {
        if (st.empty() || p[c] != st.top())
          return false;
        st.pop();
      }
    }
    return st.empty();
  }
};