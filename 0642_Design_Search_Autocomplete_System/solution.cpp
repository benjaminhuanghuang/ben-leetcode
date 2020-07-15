/*
642. Design Search Autocomplete System

Level: Hard

https://leetcode.com/problems/design-search-autocomplete-system
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
  Solution: Hashmap + sort
  补全的句子是按之前出现的频率排列的，高频率的出现在最上面，如果频率相同，就按字母顺序来显示。
  每次输入一个字符，然后返回自动补全的句子，如果遇到井字符，表示完整句子结束。
*/
class AutocompleteSystem
{
public:
  AutocompleteSystem(vector<string> sentences, vector<int> times)
  {
    for (int i = 0; i < sentences.size(); ++i)
    {
      freq[sentences[i]] += times[i];
    }
    data = "";
  }

  vector<string> input(char c)
  {
    if (c == '#')
    {
      //#表示完整句子结束
      ++freq[data];
      data = "";
      return {};
    }
    data.push_back(c);

    auto cmp = [](pair<string, int> &a, pair<string, int> &b) {
      return a.second > b.second || (a.second == b.second && a.first < b.first);
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> q(cmp);
    for (auto f : freq)
    {
      bool matched = true;
      for (int i = 0; i < data.size(); ++i)
      {
        if (data[i] != f.first[i])
        {
          matched = false;
          break;
        }
      }
      if (matched)
      {
        q.push(f);
        if (q.size() > 3)
          q.pop();
      }
    }
    vector<string> res(q.size());
    for (int i = q.size() - 1; i >= 0; --i)
    {
      res[i] = q.top().first;
      q.pop();
    }
    return res;
  }

private:
  unordered_map<string, int> freq;
  string data;
};

/*
  Solution: Trie 
  因为有空格，所以用128个子node
  因为要返回sentences， 所以每个叶子trie node要保存整个句子，
  而且每个叶子trie node要保存freq

  每个trie node还要保存前三热门的trie node
*/
struct TrieNode
{
  TrieNode() : is_word(false), times(0) {}

  ~TrieNode()
  {
    for (auto &kv : children)
      if (kv.second)
        delete kv.second;

    for (auto &n : hot)
      if (n)
        delete n;
  }

  bool is_word;
  string s;
  int times;
  vector<TrieNode*> hot;
  unordered_map<char, TrieNode *> children;
};

class AutocompleteSystem
{
public:
  AutocompleteSystem(vector<string> sentences, vector<int> times)
  {
    for (int i = 0; i < sentences.size(); ++i)
    {
      freq[sentences[i]] += times[i];
    }
    data = "";
  }

  /*
  */
  vector<string> input(char c)
  {
    if (c == '#')
    {
      //#表示完整句子结束
      ++freq[data];
      data = "";
      return {};
    }
    data.push_back(c);

    auto cmp = [](pair<string, int> &a, pair<string, int> &b) {
      return a.second > b.second || (a.second == b.second && a.first < b.first);
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> q(cmp);
    for (auto f : freq)
    {
      bool matched = true;
      for (int i = 0; i < data.size(); ++i)
      {
        if (data[i] != f.first[i])
        {
          matched = false;
          break;
        }
      }
      if (matched)
      {
        q.push(f);
        if (q.size() > 3)
          q.pop();
      }
    }
    vector<string> res(q.size());
    for (int i = q.size() - 1; i >= 0; --i)
    {
      res[i] = q.top().first;
      q.pop();
    }
    return res;
  }

private:
  unordered_map<string, int> freq;
  string data;
};
