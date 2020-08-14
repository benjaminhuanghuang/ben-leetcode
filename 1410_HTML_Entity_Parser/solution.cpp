/*
1410. HTML Entity Parser

Level: Medium

https://leetcode.com/problems/html-entity-parser
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
  Solution: Sliding window
*/
class Solution
{
private:
  unordered_map<string, string> translator{
      {"&quot;", "\""},
      {"&apos;", "'"},
      {"&amp;", "&"},
      {"&gt;", ">"},
      {"&lt;", "<"},
      {"&frasl;", "/"}};

public:
  string entityParser(string text)
  {
    string res = "";
    for (int i = 0; i < text.length(); i++)
    {
      // & 开头
      if (text[i] == '&')
      {
        int ss = i + 1; // search semicoloon
        while (ss < text.length() && text[ss] != ';')
        {
          ++ss;
        }

        // ; 结尾
        if (ss < text.length() && text[ss] == ';')
        {
          string symbol = text.substr(i, ss - i + 1);
          if (translator.count(symbol))
          {
            string replace = translator[symbol];
            res += replace;
            i = ss + 1;
            continue;
          }
        }

        if (ss == text.length())
        {
          return res + text.substr(i);
        }
        else
        {
          res += text.substr(i, ss - i + 1);
          i = ss + 1;
          continue;
        }
      }
      res += text[i];
    }
    return res;
  }
};

/*
  Solution: 
*/

class Solution
{
public:
  string entityParser(string text)
  {
    unordered_map<string, string> m{
        {"&quot;", "\""},
        {"&apos;", "'"},
        {"&amp;", "&"},
        {"&gt;", ">"},
        {"&lt;", "<"},
        {"&frasl;", "/"}};

    string ans;
    string buf;
    for (char c : text)
    {
      buf += c;
      if (buf.back() != ';')
        continue;
      const int l = buf.size();
      for (const auto &[k, v] : m)
      {
        const int kl = k.length();
        if (l >= kl && buf.substr(l - kl) == k)
        {
          ans += buf.substr(0, l - kl) + v;
          buf.clear();
          break;
        }
      }
    }
    return ans + buf;
  }
};
