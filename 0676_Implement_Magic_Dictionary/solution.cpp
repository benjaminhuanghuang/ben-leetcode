/*
676. Implement Magic Dictionary

Level: Medium

https://leetcode.com/problems/implement-magic-dictionary
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
  https://zxi.mytechroad.com/blog/hashtable/leetcode-676-implement-magic-dictionary/
*/

class MagicDictionary
{
public:
  /** Initialize your data structure here. */
  MagicDictionary()
  {
    dict_.clear();
  }

  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict)
  {
    for (string &word : dict)
    {
      for (int i = 0; i < word.length(); ++i)
      {
        char c = word[i];
        word[i] = '*';
        dict_[word].insert(c);
        word[i] = c;
      }
    }
  }

  /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
  bool search(string word)
  {
    for (int i = 0; i < word.length(); ++i)
    {
      char c = word[i];
      word[i] = '*';
      if (dict_.count(word))
      {
        const auto &char_set = dict_[word];
        if (!char_set.count(c) || char_set.size() > 1)
          return true;
      }
      word[i] = c;
    }
    return false;
  }

private:
  unordered_map<string, unordered_set<char>> dict_;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */