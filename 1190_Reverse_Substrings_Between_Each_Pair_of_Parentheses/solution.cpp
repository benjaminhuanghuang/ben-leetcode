/*
1190. Reverse Substrings Between Each Pair of Parentheses

Level: Medium

https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  string reverseParentheses(string s)
  {
    stack<string> st;
    st.push("");
    for (char c : s)
    {
      if (c == '(')
        st.push("");
      else if (c != ')')
        st.top() += c;
      else // ")"
      {
        string t = st.top();
        st.pop();


        st.top().insert(end(st.top()), rbegin(t), rend(t));
      }
    }
    return st.top();
  }
};