/*
1156. Swap For Longest Repeated Character Substring

Level: Medium

https://leetcode.com/problems/swap-for-longest-repeated-character-substring
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
  int maxRepOpt1(string text)
  {
    int n = text.length();
    // Length of repeted substring ends with text[i]
    vector<vector<int>> len1(n, vector<int>(26));
    // Length of repeated substring starts with text[i]
    vector<vector<int>> len2(n, vector<int>(26));
    vector<int> counts(26);
    int last = -1; // not a letter
    int l = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
      const int c = text[i] - 'a';
      if (c == last)
      {
        ++l;
      }
      else
      {
        last = c;
        l = 1;
      }
      len1[i][c] = l;
      len2[i - l + 1][c] = l;
      ++counts[c];
      ans = max(ans, l);
    }

    for (int i = 1; i < n - 1; ++i)
    {
      int cl = text[i - 1] - 'a';
      int cr = text[i + 1] - 'a';
      int left = len1[i - 1][cl];
      int right = len2[i + 1][cr];
      int count = 0;
      if (cl != cr)
      {
        // e.g. "c aaa b cccc" => "b aaa ccccc"
        count = max(left + (counts[cl] > left ? 1 : 0),
                    right + (counts[cr] > right ? 1 : 0));
      }
      else
      {
        // e.g. "a c aaa b aaaa" => "b c aaaaaaaa"
        count = left + right;
        if (counts[cl] > count)
          ++count;
      }
      ans = max(ans, count);
    }

    return ans;
  }
};