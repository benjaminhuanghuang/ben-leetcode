/*
1297. Maximum Number of Occurrences of a Substring

Level: Medium

https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring
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

  没有用到 maxSize， 因为要求 maximum number of ocurrences， 所以 length越短越好
*/
class Solution
{
public:
  int maxFreq(string s, int maxLetters, int minSize, int maxSize)
  {
    const int N = s.length();
    int res = 0;
    unordered_map<string, int> freqs;
    unordered_map<char, int> cnt;
    for (int i = 0; i < minSize; ++i)
      ++cnt[s[i]];
    if (cnt.size() <= maxLetters)
      ++freqs[s.substr(0, minSize)];

    for (int l = 0, r = minSize; r < N; ++l, ++r)
    {
      ++cnt[s[r]];
      --cnt[s[l]];
      if (cnt[s[l]] == 0)
        cnt.erase(s[l]);
      if (cnt.size() <= maxLetters)
      {
        auto sub = s.substr(l + 1, minSize);
        ++freqs[sub];
        res = max(res, freqs[sub]);
      }
    }
    return res;
  }
};

/*
  Reason: did not distinguish "aab" and "aba"
*/
class Solution_Wrong
{
public:
  int maxFreq(string s, int maxLetters, int minSize, int maxSize)
  {
    int ans = 0;
    unordered_set<char> Set;

    int start = 0;
    int end = 0;

    while (end < s.size())
    {
      while (end - start + 1 < minSize && end < s.size() && Set.size() <= maxLetters)
      {
        end++;
        Set.insert(s[end]);
      }

      if (end - start + 1 <= maxSize)
      {
        ans++;
      }

      Set.erase(s[start]);
      start++;
    }
    return ans;
  }
};