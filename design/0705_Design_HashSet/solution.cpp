/*
705. Design HashSet

Level: Easy

https://leetcode.com/problems/design-hashset
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
*/

class MyHashSet_V1
{
private:
  vector<int> data;

public:
  /** Initialize your data structure here. */
  MyHashSet_V1() : data(1000000, false)
  {
    //All values will be in the range of [0, 1000000].
    // data.resize(1000000, 0);
  }

  void add(int key)
  {
    data[key] = 1;
  }

  void remove(int key)
  {
    data[key] = 0;
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key)
  {
    return data[key] == 1;
  }
};

struct Node
{
  int val;
  Node *next;
  Node(int val) : val(val), next(nullptr) {}
};

const int len = 13;
class MyHashSet
{
public:
  vector<Node *> arr;
  /** Initialize your data structure here. */
  MyHashSet()
  {
    arr = vector<Node *>(len, new Node(-1));
  }

  void add(int key)
  {
    Node *temp = arr[key % len];
    if (temp->val != -1)
    {
      while (temp)
      {
        if (temp->val == key)
          return;
        if (!temp->next)
        {
          Node *node = new Node(key);
          temp->next = node;
          return;
        }
        temp = temp->next;
      }
    }
    else
    {
      temp->val = key;
    }
  }

  void remove(int key)
  {
    Node *temp = arr[key % len];
    if (temp->val != -1)
    {
      while (temp)
      {
        if (temp->val == key)
        {
          temp->val = -1;
          return;
        }
        temp = temp->next;
      }
    }
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key)
  {
    Node *temp = arr[key % len];
    while (temp)
    {
      if (temp->val == key)
        return true;
      temp = temp->next;
    }
    return false;
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */