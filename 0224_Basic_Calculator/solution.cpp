/*
224. Basic Calculator

Level: Hard

https://leetcode.com/problems/basic-calculator
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
#include <functional>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution:  Recursion

    Make a recursive call when there is an open parenthesis and return if there is close parenthesis.

    Time complexity: O(n)
    Space complexity: O(n)
*/

class Solution
{
public:
  int calculate(string s)
  {
    function<int(int &)> eval = [&](int &pos) {
      int ret = 0;
      int sign = 1;
      int val = 0;
      while (pos < s.size())
      {
        const char ch = s[pos];
        if (isdigit(ch))
        {
          val = val * 10 + (s[pos++] - '0');
        }
        else if (ch == '+' || ch == '-')
        {
          ret += sign * val;
          val = 0;
          sign = ch == '+' ? 1 : -1;
          ++pos;
        }
        else if (ch == '(')
        {
          val = eval(++pos);
        }
        else if (ch == ')')
        {
          ++pos;
          break;
        }
        else
        {
          ++pos;
        }
      }
      return ret += sign * val;
    };
    int pos = 0;
    return eval(pos);
  }
};

/*

    https://www.youtube.com/watch?v=ijyUwyt5vkU
    认为只有加法， 遇到"+， -"赋值给sign， 遇到数字和sign， 遇到"("压栈
*/

class Solution_Stack
{
public:
  int calculate(string s)
  {
    stack<int> stack;

    int ans = 0;
    int sign = 1; // "+"

    for (int i = 0; i < s.size(); i++)
    {
      char c = s[i];

      if (c == ' ')
        continue;

      if (c == '+')
      {
        sign = 1;
      }
      else if (c == '-')
      {
        sign = -1;
      }
      else if (c == '(')
      {
        stack.push(ans);
        stack.push(sign);
        ans = 0;
        sign = 1;
      }
      else if (c == ')')
      {
        ans *= stack.top();
        stack.pop(); // current ans = current ans * sign
        ans += stack.top();
        stack.pop(); // previous ans
      }
      else
      {
        int num = c - '0';
        while (i + 1 < s.length() && isdigit(s[i + 1]))
        {
          num = num * 10 + s[i + 1] - '0';
          i++;
        }
        ans += num * sign;
      }
    }
    return ans;
  }
};