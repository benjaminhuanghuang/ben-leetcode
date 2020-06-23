/*
455. Assign Cookies

Level: Easy

https://leetcode.com/problems/assign-cookies
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

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
  int findContentChildren(vector<int> &g, vector<int> &s)
  {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i_g = g.size() - 1;
    int i_s = s.size() - 1;
    int ans = 0;
    while (i_g >= 0 && i_s >= 0)
    {
      if (s[i_s] >= g[i_g])
      {
        ans++;
        i_s--;
      }
      i_g--;
    }
    return ans;
  }
};