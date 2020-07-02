/*
139. Word Break

Level: Medium

https://leetcode.com/problems/word-break


- 140. Word Break II
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
  /*
    Hua Hua
    https://www.youtube.com/watch?v=ptlwluzeC1I

    wordBreak("leetcode") = wordBreak("") && inDict("leetcode")
    ...
    wordBreak("leetcode") = wordBreak("leet") && inDict("code")
    ...
    wordBreak("leetcode") = wordBreak("leetcod") && inDict("e")
  */
  bool wordBreak(string s, vector<string> &wordDict)
  {
    // create a hashset of words for fast query
    unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());

    return wordBreak(s, dict);
  }

  bool wordBreak(const string &s, const unordered_set<string> &dict)
  {
    if (mem.count(s))
      return mem[s];
    if (dict.count(s)) //memorize and return
    {
      // split to "" and s
      return mem[s] = true;
    }

    for (int i = 1; i < s.length(); i++)
    {
      const string left = s.substr(0, i);
      const string right = s.substr(i);

      if (dict.count(right) && wordBreak(left, dict))
      {
        return mem[s] = true;
      }
    }

    return mem[s] = false;
  }

private:
  unordered_map<string, bool> mem;
};