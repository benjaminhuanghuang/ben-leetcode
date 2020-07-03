/*
146. LRU Cache

Level: Medium

https://leetcode.com/problems/lru-cache

- 460. LFU Cache
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <list>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  https://www.youtube.com/watch?v=q1Njd3NWvlY

  O(1) 不能用 vector
  list used to inster, delete O(1)
*/

class LRUCache
{
public:
  LRUCache(int n)
  {
    capacity = n;
  }

  int get(int key)
  {
    const auto it = m.find(key);

    if (it == m.cend()) // key doest not exist
      return -1;
    // move the node to the front of list
    cache.splice(cache.begin(), cache, it->second);
    return it->second->second;
  }

  void put(int key, int value)
  {
    const auto it = m.find(key);
    
    if (it != m.cend()) // Key already exists
    {
      // update
      it->second->second = value;
      // move the node to the front of list
      cache.splice(cache.begin(), cache, it->second);
      return;
    }

    if (cache.size() == capacity)
    {
      // remove the oldest node
      const auto &node = cache.back();
      m.erase(node.first);
      cache.pop_back();
    }

    // insert
    cache.emplace_front(key, value); // emplace_front create a node
    m[key] = cache.begin();
  }

private:
  int capacity;
  list<pair<int, int>> cache;
  // get lisk node by key
  unordered_map<int, list<pair<int, int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */