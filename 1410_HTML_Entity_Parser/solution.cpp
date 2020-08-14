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
  Solution: 
*/

class Solution
{
public:
  string entityParser(string text)
  {
    unordered_map<string, string> m{
        {"&quot;", "\""}, {"&apos;", "'"}, {"&amp;", "&"}, {"&gt;", ">"}, {"&lt;", "<"}, {"&frasl;", "/"}};
    
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