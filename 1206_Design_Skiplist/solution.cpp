/*
1206. Design Skiplist

Level: Hard

https://leetcode.com/problems/design-skiplist
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Skiplist
{
  multiset<int> sec;

public:
  Skiplist()
  {
  }

  bool search(int target)
  {
    return (sec.find(target) != sec.end());
  }

  void add(int num)
  {
    sec.insert(num);
  }

  bool erase(int num)
  {
    multiset<int>::iterator it = sec.find(num);
    bool ret = (it != sec.end());
    if (ret)
      sec.erase(it);
    return ret;
  }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */