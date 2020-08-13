/*
1233. Remove Sub-Folders from the Filesystem

Level: Medium

https://leetcode.com/problems/remove-sub-folders-from-the-filesystem
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
  HashTable

    Time complexity: O(n*L)
    Space complexity: O(n*L)
*/

class Solution
{
public:
  vector<string> removeSubfolders(vector<string> &folder)
  {
    unordered_set<string> s(begin(folder), end(folder));
    vector<string> ans;

    for (const auto &cur : folder)
    {
      string f = cur;
      bool valid = true;
      // remove sub-folders from current f
      while (!f.empty() && valid)
      {
        while (f.back() != '/')
          f.pop_back();
        f.pop_back();
        if (s.count(f))
          valid = false;
      }
      if (valid)
        ans.push_back(cur);
    }
    return ans;
  }
};