/*
1319. Number of Operations to Make Network Connected

Level: Medium

https://leetcode.com/problems/number-of-operations-to-make-network-connected
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
  int makeConnected(int n, vector<vector<int>> &connections)
  {
    if (connections.size() < n - 1)
      return -1;
    vector<int> p(n);
    iota(begin(p), end(p), 0);

    function<int(int)> find = [&](int x) {
      return p[x] == x ? x : p[x] = find(p[x]);
    };

    for (const auto &c : connections)
      p[find(c[0])] = find(c[1]);

    unordered_set<int> s;
    for (int i = 0; i < n; ++i)
      s.insert(find(i));

    return s.size() - 1;
  }
};


class Solution {
public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1;
    vector<vector<int>> g(n);
    for (const auto& c : connections) {
      g[c[0]].push_back(c[1]);
      g[c[1]].push_back(c[0]);
    }
    vector<int> seen(n);
    int count = 0;

    function<void(int)> dfs = [&](int cur) {
      for (int nxt : g[cur])
        if (!seen[nxt]++) dfs(nxt);      
    };
    
    for (int i = 0; i < n; ++i)
      if (!seen[i]++ && ++count)
        dfs(i);        
    return count - 1;
  }
};