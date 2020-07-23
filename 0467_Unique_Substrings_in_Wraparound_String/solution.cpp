/*
467. Unique Substrings in Wraparound String

Level: Medium

https://leetcode.com/problems/unique-substrings-in-wraparound-string
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
  给一个字符串P，需要从其中找到所有出现在  infinite wraparound string S中的子串。

  Solution: 
*/

class Solution
{
public:
  int findSubstringInWraproundString(string p)
  {
    vector<int> p_int(p.size());
    vector<int> count(26);

    //记录每个位置的字符
    for (int i = 0; i < p.length(); i++)
    {
      p_int[i] = p[i] - 'a';
    }
    int res = 0;
    int maxLen = 0;
    for (int i = 0; i < p.size(); i++)
    {
      // 递增
      if (i > 0 && (p_int[i - 1] + 1) % 26 == p_int[i])
      {
        maxLen++;
      }
      else
      {
        maxLen = 1;
      }
      count[p_int[i]] = max(count[p_int[i]], maxLen);
    }
    for (int i = 0; i < 26; i++)
      res += count[i];
    return res;
  }
};