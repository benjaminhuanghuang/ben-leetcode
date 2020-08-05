/*
1324. Print Words Vertically

Level: Medium

https://leetcode.com/problems/print-words-vertically
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
  vector<string> printVertically(string s)
  {
    vector<string> v;
    string t;
    int m = 0;
    for (int i = 0; i <= s.length(); i++)
    {
      if (i == s.length() || s[i] == ' ')
      {
        if (m < t.length())
          m = t.length();
        v.push_back(t);
        t.clear();
      }
      else
      {
        t += s[i];
      }
    }

    vector<string> ans;
    for (int j = 0; j < m; j++)
    {
      for (int i = 0; i < v.size(); i++)
        if (j < v[i].length())
          t += v[i][j];
        else
          t += ' ';

      while (t.back() == ' ')
        t.pop_back();
      ans.push_back(t);
      t.clear();
    }

    return ans;
  }
};