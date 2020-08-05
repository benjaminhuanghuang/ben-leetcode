/*
721. Accounts Merge

Level: Medium

https://leetcode.com/problems/accounts-merge
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>
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
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
  {
    unordered_map<string_view, int> ids;   // email to id
    unordered_map<int, string_view> names; // id to name
    vector<int> p(10000);
    iota(begin(p), end(p), 0);

    function<int(int)> find = [&](int x) {
      if (p[x] != x)
        p[x] = find(p[x]);
      return p[x];
    };

    auto getIdByEmail = [&](string_view email) {
      auto it = ids.find(email);
      if (it == ids.end())
      {
        int id = ids.size();
        return ids[email] = id;
      }
      return it->second;
    };

    for (const auto &account : accounts)
    {
      int u = find(getIdByEmail(account[1]));
      for (int i = 2; i < account.size(); ++i)
        p[find(u)] = find(getIdByEmail(account[i]));
      names[find(u)] = string_view(account[0]);
    }

    unordered_map<int, set<string>> mergered;
    for (const auto &account : accounts)
      for (int i = 1; i < account.size(); ++i)
      {
        int id = find(getIdByEmail(account[i]));
        mergered[id].insert(account[i]);
      }

    vector<vector<string>> ans;
    for (const auto &kv : mergered)
    {
      ans.push_back({string(names[kv.first])});
      ans.back().insert(ans.back().end(), kv.second.begin(), kv.second.end());
    }

    return ans;
  }
};