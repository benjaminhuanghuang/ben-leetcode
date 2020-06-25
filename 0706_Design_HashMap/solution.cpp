/*
706. Design HashMap

Level: Easy

https://leetcode.com/problems/design-hashmap
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <list>
#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class MyHashMap
{
  vector<list<pair<int, int>>> table;
  int m = 2069; // pick a large prime number
public:
  /** Initialize your data structure here. */
  MyHashMap()
  {
    table.resize(m);
  }

  /** value will always be non-negative. */
  void put(int key, int value)
  {
    auto &ls = table[key % m];
    for (auto &p : ls)
    {
      if (p.first == key)
      {
        p.second = value;
        return;
      }
    }
    ls.push_back({key, value});
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
  int get(int key)
  {
    auto &ls = table[key % m];
    for (auto &p : ls)
    {
      if (p.first == key)
        return p.second;
    }
    return -1;
  }

  /** Removes the mapping of the specified value key if this map contains a mapping for the key */
  void remove(int key)
  {
    auto &ls = table[key % m];
    for (auto &p : ls)
    {
      if (p.first == key)
      {
        ls.remove(p);
        return;
      }
    }
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */