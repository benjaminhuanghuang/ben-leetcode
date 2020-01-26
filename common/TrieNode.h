/*
http://zxi.mytechroad.com/blog/data-structure/leetcode-208-implement-trie-prefix-tree/
*/

#ifndef __TRIENODE_H__
#define __TRIENODE_H__

#include <string>
using namespace std;

class TrieNode
{
public:
  ~TrieNode()
  {
    for (auto node : _children)
    {
      delete node;
    }
  }
  void reverse_build(const string &s, int i)
  {
    if (i == -1)
    {
      isWordEnd = true;
      return;
    }
    const int index = s[i] - 'a';
    if (!_children[index])
      _children[index] = new TrieNode();
    _children[index]->reverse_build(s, i - 1);
  }

  bool reverse_search(const string &s, int i)
  {
    if (i == -1 || isWordEnd)
      return isWordEnd;

    const int index = s[i] - 'a';
    if (!_children[index])
      return false;
    return _children[index]->reverse_search(s, i - 1);
  }

private:
  bool isWordEnd = false; // is last char of a word
  TrieNode *_children[26] = {0};
};
#endif
