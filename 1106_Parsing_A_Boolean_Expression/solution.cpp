/*
1106. Parsing A Boolean Expression

Level: Hard

https://leetcode.com/problems/parsing-a-boolean-expression
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
  https://zxi.mytechroad.com/blog/recursion/leetcode-1106-parsing-a-boolean-expression/

  Solution: Recursion

    Time complexity: O(n)    每个字符处理一次
    Space complexity: O(n)   depth = N
*/

class Solution
{
public:
  bool parseBoolExpr(string expression)
  {
    int s = 0;
    return parse(expression, s);
  }

private:
  // s: index of current char
  bool parse(const string &exp, int &s)
  {
    char ch = exp[s++];
    if (ch == 't')
      return true;
    if (ch == 'f')
      return false;
    if (ch == '!')
    {
      bool ans = !parse(exp, ++s); // ++s : skip '('
      ++s;                         // ++s : skip ')'
      return ans;
    }
    bool is_and = (ch == '&');
    bool ans = is_and;
    ++s;
    while (true)
    {
      if (is_and)
        ans &= parse(exp, s);
      else
        ans |= parse(exp, s);
      if (exp[s++] == ')')
        break;
    }
    return ans;
  }
};

/*
https://www.acwing.com/solution/LeetCode/content/2653/
*/

class Solution
{
public:
  bool parse(const string &expression, int &cur)
  {
    // 需要实时维护当前位置，所以 cur 要取引用。
    if (expression[cur] == 't')
    {
      cur++;
      return true;
    }
    else if (expression[cur] == 'f')
    {
      cur++;
      return false;
    }
    else if (expression[cur] == '!')
    {
      cur += 2;
      bool ret = !parse(expression, cur);
      cur++;
      return ret;
    }
    else if (expression[cur] == '&')
    {
      cur += 2;
      bool ret = true;
      while (true)
      {
        ret &= parse(expression, cur);
        cur++;
        if (expression[cur - 1] == ')')
          break;
      }
      return ret;
    }
    else
    {
      cur += 2;
      bool ret = false;
      while (true)
      {
        ret |= parse(expression, cur);
        cur++;
        if (expression[cur - 1] == ')')
          break;
      }
      return ret;
    }
  }

  bool parseBoolExpr(string expression)
  {
    int cur = 0;
    return parse(expression, cur);
  }
};
