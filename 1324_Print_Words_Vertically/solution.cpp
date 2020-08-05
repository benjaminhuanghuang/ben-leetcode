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
    vector<string> words;
    string word;
    int max_word_len = 0;
    for (int i = 0; i <= s.length(); i++)
    {
      if (i == s.length() || s[i] == ' ') // end of word
      {
        if (max_word_len < word.length())
          max_word_len = word.length();
        words.push_back(word);
        word.clear();
      }
      else
      {
        word += s[i];
      }
    }

    vector<string> ans;
    for (int j = 0; j < max_word_len; j++)
    {
      for (int i = 0; i < words.size(); i++)
        if (j < words[i].length())
          word += words[i][j];
        else
          word += ' ';

      while (word.back() == ' ')
        word.pop_back();
      ans.push_back(word);
      word.clear();
    }

    return ans;
  }
};