/*
424. Longest Repeating Character Replacement

Level: Medium

https://leetcode.com/problems/longest-repeating-character-replacement
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
  Slide window: [start, i]

*/

class Solution
{
public:
  int characterReplacement(string s, int k)
  {
    int res = 0, maxCount = 0, start = 0;
    int counts[26] = {0};

    for (int i = 0; i < s.length(); ++i)
    {
      ++counts[s[i] - 'A'];
      // 出现最多字符的个数
      maxCount = max(maxCount, counts[s[i] - 'A']);
      // 如果 A 出现的次数最多，只要把 除过 A的字符改掉，就能得到一个全A的字符串
      // 保证子字符串的长度减去出现次数最多的字符个数<=k
      while (i - start + 1 - maxCount > k)
      {
        --counts[s[start] - 'A'];
        ++start;
      }
      res = max(res, i - start + 1);
    }
    return res;
  }
};