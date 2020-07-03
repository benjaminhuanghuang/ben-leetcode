/*
208. Implement Trie (Prefix Tree)

Level: Medium

https://leetcode.com/problems/implement-trie-prefix-tree
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
  https://zxi.mytechroad.com/blog/data-structure/leetcode-208-implement-trie-prefix-tree/
  Time complexity: O(l)  l is length of word
  Space complexity: O(prefixes)   O(n*l^2)
*/

class Trie_HashMap
{
public:
  /** Initialize your data structure here. */
  Trie_HashMap() : root_(new TrieNode())
  {
  }

  /** Inserts a word into the trie. */
  void insert(string word)
  {
    TrieNode *p = root_.get();
    for (const char c : word)
    {
      if (!p->children.count(c))
        p->children[c] = new TrieNode();
      p = p->children[c];
    }
    p->is_word = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word)
  {
    const TrieNode *p = find(word);
    return p && p->is_word;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix)
  {
    return find(prefix) != nullptr;
  }

  struct TrieNode
  {
    TrieNode() : is_word(false) {}

    ~TrieNode()
    {
      for (auto &kv : children)
        if (kv.second)
          delete kv.second;
    }

    bool is_word;
    unordered_map<char, TrieNode *> children;
  };

  const TrieNode *find(const string &prefix) const
  {
    const TrieNode *p = root_.get();   // get point from unique_ptr
    for (const char c : prefix)
    {
      if (!p->children.count(c))
        return nullptr;
      p = p->children.at(c);
    }
    return p;
  }

  std::unique_ptr<TrieNode> root_;
};

class Trie_Array
{
public:
  /** Initialize your data structure here. */
  Trie_Array() : root_(new TrieNode()) {}

  /** Inserts a word into the trie. */
  void insert(const string &word)
  {
    TrieNode *p = root_.get();
    for (const char c : word)
    {
      if (!p->children[c - 'a'])
        p->children[c - 'a'] = new TrieNode();
      p = p->children[c - 'a'];
    }
    p->is_word = true;
  }

  /** Returns if the word is in the trie. */
  bool search(const string &word) const
  {
    const TrieNode *p = find(word);
    return p && p->is_word;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(const string &prefix) const
  {
    return find(prefix) != nullptr;
  }

private:
  struct TrieNode
  {
    TrieNode() : is_word(false), children(26, nullptr) {}

    ~TrieNode()
    {
      for (TrieNode *child : children)
        if (child)
          delete child;
    }

    bool is_word;
    vector<TrieNode *> children;
  };

  const TrieNode *find(const string &prefix) const
  {
    const TrieNode *p = root_.get();
    for (const char c : prefix)
    {
      p = p->children[c - 'a'];
      if (p == nullptr)
        break;
    }
    return p;
  }

  std::unique_ptr<TrieNode> root_;
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */