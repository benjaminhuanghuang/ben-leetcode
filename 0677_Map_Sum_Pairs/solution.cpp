/*
677. Map Sum Pairs

Level: Medium

https://leetcode.com/problems/map-sum-pairs
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
  http://zxi.mytechroad.com/blog/tree/leetcode-677-map-sum-pairs/
*/
class MapSum
{
public:
  /** Initialize your data structure here. */
  MapSum() {}

  void insert(const string &key, int val)
  {
    int inc = val;
    if (vals_.count(key))
    {
      inc -= vals_[key];
    }
    vals_[key] = val;
    for (int i = 1; i <= key.length(); ++i)
      sums_[key.substr(0, i)] += inc;
  }

  int sum(const string &prefix)
  {
    return sums_[prefix];
  }

private:
  unordered_map<string, int> vals_;
  unordered_map<string, int> sums_;
};

class MapSum
{
public:
  /** Initialize your data structure here. */
  MapSum()
  {
  }

  void insert(string key, int val)
  {
    int inc = val - vals_[key];
    Trie *p = &root;
    for (const char c : key)
    {
      if (!p->children[c])
        p->children[c] = new Trie();
      p->children[c]->sum += inc;
      p = p->children[c];
    }
    vals_[key] = val;
  }

  int sum(string prefix)
  {
    Trie *p = &root;
    for (const char c : prefix)
    {
      if (!p->children[c])
        return 0;
      p = p->children[c];
    }
    return p->sum;
  }

private:
  struct Trie
  {
    Trie() : children(128, nullptr), sum(0) {}
    ~Trie()
    {
      for (auto child : children)
        if (child)
          delete child;
      children.clear();
    }
    vector<Trie *> children;
    int sum;
  };
  Trie root;                        // dummy root
  unordered_map<string, int> vals_; // key -> val
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */