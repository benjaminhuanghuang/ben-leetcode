/*
211. Add and Search Word - Data structure design

string containing only letters a-z or '.'

https://leetcode.com/problems/add-and-search-word-data-structure-design/

*/

#include <array>
#include <vector>
#include <string>

using namespace std;

class WordDictionary
{
public:
  //data structure
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

  /** Initialize your data structure here. */
  WordDictionary(): root(new TrieNode())
  {
  }

  /** Adds a word into the data structure. */
  void addWord(string word)
  {
    TrieNode *node = root.get();
    for (int i = 0; i < word.length(); i++)
    {
      char ch = word[i];
      if (node->children[ch - 'a'] == nullptr)
        node->children[ch - 'a'] = new TrieNode();
      node = node->children[ch - 'a'];
    }
    node->is_word = true;
  }

  /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
  bool search(string word)
  {
    return match(word, 0, root.get());
  }

private:
  unique_ptr<TrieNode> root;

  bool match(string &word, int index, TrieNode *node)
  {
    if (index == word.length())
      return node->is_word; //because root is NULL

    if (word[index] != '.')
    {
      return node->children[word[index] - 'a'] && match(word, index + 1, node->children[word[index] - 'a']);
    }
    else
    { //backtracking: set of options which is links[i],try each recursively
      for (int i = 0; i < node->children.size(); i++)
      { //recur any links of '.'
        if (node->children[i] && match(word, index + 1, node->children[i]))
        {
          return true; //if there is match, we just return true
        }              //if not match, we just skip to next one, until no char left and we ensure no match
      }
    }
    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */