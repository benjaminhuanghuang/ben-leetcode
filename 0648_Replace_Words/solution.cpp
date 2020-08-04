/*
648. Replace Words

Level: Medium

https://leetcode.com/problems/replace-words
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
#include <sstream>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  Time complexity: O(sum(w^2))

  Space complexity: O(sum(l))
*/

class Solution
{
public:
  string replaceWords(vector<string> &dict, string sentence)
  {
    unordered_set<string> d(begin(dict), end(dict));
    sentence.push_back(' ');
    string output;
    string word;
    bool found = false;
    for (char c : sentence)
    {
      if (c == ' ')
      {
        if (!output.empty())
          output += ' ';
        output += word;
        word = "";
        found = false;
        continue;
      }
      if (found)
        continue;
      word += c;
      if (d.count(word))
      {
        found = true;
      }
    }
    return output;
  }
};


class TrieNode {
public:
  TrieNode(): children(26), is_word(false) {}
  ~TrieNode() {
    for (int i = 0; i < 26; ++i)
      if (children[i]) {
        delete children[i];
        children[i] = nullptr;
      }
  }
  vector<TrieNode*> children;
  bool is_word;
};

/*
Time complexity: O(sum(l) + n)

Space complexity: O(sum(l) * 26)
*/
class Solution {
public:
  string replaceWords(vector<string>& dict, string sentence) {    
    TrieNode root;
    for (const string& word : dict) {
      TrieNode* cur = &root;
      for (char c : word) {        
        if (!cur->children[c - 'a']) 
          cur->children[c - 'a'] = new TrieNode();
        cur = cur->children[c - 'a'];
      }
      cur->is_word = true;
    }
    
    string ans;
    stringstream ss(sentence);
    string word;
    while (ss >> word) {      
      TrieNode* cur = &root;
      bool found = false;
      int len = 0;
      for (char c : word) {        
        cur = cur->children[c - 'a'];        
        if (!cur) break;
        ++len;
        if (cur->is_word) {
          found = true;
          break;
        }
      }      
      if (!ans.empty()) ans += ' ';      
      ans += found ? word.substr(0, len) : word;
    }
    return ans;
  }
};