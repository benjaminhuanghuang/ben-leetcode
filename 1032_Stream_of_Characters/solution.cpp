/*
  1032. Stream of Characters

  https://leetcode.com/problems/stream-of-characters/

*/
#include <vector>
#include <string>
#include <memory>

#include "common/TrieNode.h"

using namespace std;
/*

  [# 208]

   searching from end to start
*/
class StreamChecker
{
public:
  StreamChecker(vector<string> &words)
  {
    _root = std::make_unique<TrieNode>();
    for (const string &w : words)
    {
      _root->reverse_build(w, w.length() - 1);
    }
  }

  bool query(char letter)
  {
    _s += letter;
    return _root->reverse_search(_s, _s.length() - 1);
  }

private:
  // search 
  string _s;
  // unique_ptr will be disposed when it gose out of acope
  unique_ptr<TrieNode> _root;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */