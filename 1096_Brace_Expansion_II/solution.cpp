/*
1096. Brace Expansion II

Level: Hard

https://leetcode.com/problems/brace-expansion-ii
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 

  https://www.acwing.com/solution/LeetCode/content/2654/
  
*/

class Solution
{
public:
  set<string> multiply(const set<string> &x, const set<string> &y)
  {
    set<string> ans;
    for (auto &a : x)
      for (auto &b : y)
        ans.insert(a + b);

    return ans;
  }

  set<string> parse(const string &expr, int &cur)
  {
    set<string> result;
    if (expr[cur] >= 'a' && expr[cur] <= 'z')
    {
      // 当前位置为小写字母。
      string t(1, expr[cur]);
      result.insert(t);
      cur++;
    }
    else
    {
      result.insert("");
      while (expr[cur] == '{')
      {
        // 当前位置是 `{`。
        cur++;
        set<string> ret;
        while (true)
        {
          // 处理以 `,` 分隔的集合。
          set<string> r(parse(expr, cur));
          ret.insert(r.begin(), r.end());
          cur++;
          if (expr[cur - 1] == '}')
            break;
        }
        // 处理以 `{}` 连接的集合。
        result = multiply(result, ret);
      }
    }
    return result;
  }

  vector<string> braceExpansionII(string expression)
  {
    string expr;
    for (auto &c : expression)
    {
      if (c >= 'a' && c <= 'z')
      {
        expr += "{";
        expr += c;
        expr += "}";
      }
      else
        expr += c;
    }
    int cur = 0;
    set<string> ans(parse(expr, cur));
    return vector<string>(ans.begin(), ans.end());
  }
};
