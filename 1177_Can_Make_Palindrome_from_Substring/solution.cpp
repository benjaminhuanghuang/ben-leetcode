/*
1177. Can Make Palindrome from Substring

Level: Medium

https://leetcode.com/problems/can-make-palindrome-from-substring
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
  https://www.youtube.com/watch?v=kzieK4JJtc0
*/

class Solution
{
public:
  vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
  {
    vector<bool> ans;
    int n = s.length();
    vector<vector<int>> f(n + 1, vector<int>(26));
    for (int i = 0; i < n; ++i)
    {
      ++f[i][s[i] - 'a'];
      f[i + 1] = f[i];
    }
    for (const auto &q : queries)
    {
      int l = q[0];
      int r = q[1];
      int k = q[2];
      int o = 0;
      for (int i = 0; i < 26; ++i)
      {
        int c = f[r][i] - (l == 0 ? 0 : f[l - 1][i]);
        o += c % 2;
      }
      ans.push_back(o / 2 <= k);
    }
    return ans;
  }
};