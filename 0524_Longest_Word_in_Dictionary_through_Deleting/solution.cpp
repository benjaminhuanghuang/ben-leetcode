/*
524. Longest Word in Dictionary through Deleting

Level: Medium

https://leetcode.com/problems/longest-word-in-dictionary-through-deleting
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

  https://www.cnblogs.com/grandyang/p/6523344.html
*/

class Solution
{
public:
  string findLongestWord(string s, vector<string> &d)
  {
    sort(d.begin(), d.end(), [](string a, string b) {
      if (a.size() == b.size())
        return a < b;
      return a.size() > b.size();
    });

    for (string word : d)
    {
      int i = 0;
      for (char c : s)
      {
        if (i < word.size() && c == word[i])
          ++i;
      }
      if (i == word.size())
        return word;
    }
    return "";
  }
};