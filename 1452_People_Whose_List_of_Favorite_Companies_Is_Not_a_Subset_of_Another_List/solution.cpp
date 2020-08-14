/*
1452. People Whose List of Favorite Companies Is Not a Subset of Another List

Level: Medium

https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list
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
  vector<int> peopleIndexes(vector<vector<string>> &favoriteCompanies)
  {
    const int n = favoriteCompanies.size();
    vector<unordered_set<string>> m;
    for (const auto &c : favoriteCompanies)
      m.emplace_back(begin(c), end(c));
      
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
      bool valid = true;
      for (int j = 0; j < n && valid; ++j)
      {
        if (i == j)
          continue;
        bool subset = true;
        for (const auto &s : m[i])
          if (!m[j].count(s))
          {
            subset = false;
            break;
          }
        if (subset)
        {
          valid = false;
          break;
        }
      }
      if (valid)
        ans.push_back(i);
    }
    return ans;
  }
};