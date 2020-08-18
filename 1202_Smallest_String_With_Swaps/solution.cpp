/*
1202. Smallest String With Swaps

Level: Medium

https://leetcode.com/problems/smallest-string-with-swaps
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
  https://zxi.mytechroad.com/blog/graph/leetcode-1202-smallest-string-with-swaps/
  
  Solution: DFS
*/

class Solution
{
public:
  string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
  {
    vector<vector<int>> g(s.length());
    for (const auto &e : pairs)
    {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }

    unordered_set<int> seen;
    vector<int> idx;
    string tmp;
    function<void(int)> dfs = [&](int cur) {
      if (seen.count(cur))
        return;
      seen.insert(cur);
      idx.push_back(cur);
      tmp += s[cur];
      for (int nxt : g[cur])
        dfs(nxt);
    };

    for (int i = 0; i < s.length(); ++i)
    {
      if (seen.count(i))
        continue;
      idx.clear();
      tmp.clear();
      dfs(i);
      sort(begin(tmp), end(tmp));
      sort(begin(idx), end(idx));
      for (int k = 0; k < idx.size(); ++k)
        s[idx[k]] = tmp[k];
    }
    return s;
  }
};

/*
  https://zxi.mytechroad.com/blog/graph/leetcode-1202-smallest-string-with-swaps/
  Solution: Union Find

*/

class Solution
{
public:
  string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
  {
    int n = s.length();
    vector<int> p(n);
    iota(begin(p), end(p), 0); // p = {0, 1, 2, ... n - 1}

    function<int(int)> find = [&](int x) {
      return p[x] == x ? x : p[x] = find(p[x]);
    };

    for (const auto &e : pairs)
      p[find(e[0])] = find(e[1]); // union

    vector<vector<int>> idx(n);
    vector<string> ss(n);

    for (int i = 0; i < s.length(); ++i)
    {
      int id = find(i);
      idx[id].push_back(i); // already sorted
      ss[id].push_back(s[i]);
    }

    for (int i = 0; i < n; ++i)
    {
      sort(begin(ss[i]), end(ss[i]));
      for (int k = 0; k < idx[i].size(); ++k)
        s[idx[i][k]] = ss[i][k];
    }

    return s;
  }
};