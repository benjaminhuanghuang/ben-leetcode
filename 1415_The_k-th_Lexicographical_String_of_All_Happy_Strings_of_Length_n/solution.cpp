/*
1415. The k-th Lexicographical String of All Happy Strings of Length n

Level: Medium

https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n
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
  递归按照字典序直接构造合法字符串，到达长度 n 时，k 减 1，直到 k 为 0 时的当前字符串为答案。
  https://www.youtube.com/watch?v=cFmErGEEw9E
*/
class Solution
{
public:
  string getHappyString(int n, int k)
  {
    string tmp;
    string res;

    helper(tmp, res, n, k);

    return k < 0 ? "" : res;
  }

private:
  void helper(string tmp, string &res, int n, int &k)
  {
    if (k < 0)
    {
      return;
    }

    if (n == 0)
    {
      if (--k == 0)
      {
        res = tmp;
      }
      return;
    }

    for (char ch = 'a'; ch <= 'c'; ++ch)
    {
      if (tmp.length() != 0 && ch == tmp.back())
        continue;
      tmp.push_back(ch);
      helper(tmp, res, n - 1, k);
      tmp.pop_back();
    }
  }
};

class Solution
{
public:
  string getHappyString(int n, int k)
  {
    string ans;
    string cur;

    function<void()> dfs = [&]() {
      if (k <= 0)
        return;
      if (cur.length() == n)
      {
        if (--k == 0)
          ans = cur;
        return;
      }
      for (char ch = 'a'; ch <= 'c'; ++ch)
      {
        if (!cur.empty() && ch == cur.back())
          continue;
        cur.push_back(ch);
        dfs();
        cur.pop_back();
      }
    };

    dfs();
    return k > 0 ? "" : ans;
  }
};