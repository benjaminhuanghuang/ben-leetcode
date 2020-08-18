/*
1255. Maximum Score Words Formed by Letters

Level: Hard

https://leetcode.com/problems/maximum-score-words-formed-by-letters
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
  https://www.youtube.com/watch?v=1XMpzhFUvco
*/

class Solution
{
public:
  int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
  {
    vector<int> counts(26);
    vector<int> scores(words.size());
    for (char c : letters)
      ++counts[c - 'a'];
    for (int i = 0; i < words.size(); ++i)
      for (char c : words[i])
        scores[i] += score[c - 'a'];
    int ans = 0;

    function<void(int, int)> dfs = [&](int s, int cur) {
      if (cur > ans)
        ans = cur;
      for (int i = s; i < words.size(); ++i)
      {
        bool valid = true;
        for (char c : words[i])
          valid &= --counts[c - 'a'] >= 0;
        if (valid)
          dfs(i + 1, cur + scores[i]);
        for (char c : words[i])
          ++counts[c - 'a'];
      }
    };

    dfs(0, 0);
    return ans;
  }
};