/*
1239. Maximum Length of a Concatenated String with Unique Characters

Level: Medium

https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters
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
  https://zxi.mytechroad.com/blog/searching/leetcode-1239-maximum-length-of-a-concatenated-string-with-unique-characters/
*/

class Solution
{
public:
  int maxLength(vector<string> &arr)
  {
    vector<int> a;

    for (const string &x : arr)
    {
      set<char> s(begin(x), end(x));
      if (s.size() != x.length())
        continue;
      a.push_back(0);
      for (char c : x)
        a.back() |= 1 << (c - 'a');
    }

    int ans = 0;

    function<void(int, int)> dfs = [&](int s, int cur) {
      ans = max(ans, __builtin_popcount(cur));
      for (int i = s; i < a.size(); ++i)
        if ((cur & a[i]) == 0)
          dfs(i + 1, cur | a[i]);
    };

    dfs(0, 0);
    return ans;
  }
};