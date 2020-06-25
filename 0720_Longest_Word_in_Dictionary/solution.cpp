/*
720. Longest Word in Dictionary

Level: Easy

https://leetcode.com/problems/longest-word-in-dictionary
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
  string longestWord(vector<string> &words)
  {
    sort(words.begin(), words.end());

    unordered_set<string> set;
    string res = "";

    for (string word : words)
    {
      if (word.length() == 1 || set.count(word.substr(0, word.length() - 1)))
      {
        // 遍历words，遇到长度等于 1的 word 或者 这个word 去掉最后一个char 已经存在于 set
        res = word.length() > res.length() ? word : res; // keep the longer one
        set.insert(word);
      }
    }

    return res;
  }

  string longestWord2(vector<string> &words)
  {
    string best;
    unordered_set<string> dict(words.begin(), words.end());
    for (const string &word : words)
    {
      if (word.length() < best.length() || (word.length() == best.length() && word > best))
        continue;
      string prefix;
      bool valid = true;
      for (int i = 0; i < word.length() - 1 && valid; ++i)
      {
        prefix += word[i];
        if (!dict.count(prefix))
          valid = false;
      }
      if (valid)
        best = word;
    }
    return best;
  }
};