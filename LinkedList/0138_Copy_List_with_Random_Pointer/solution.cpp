/*
138. Copy List with Random Pointer

Level: Medium

https://leetcode.com/problems/copy-list-with-random-pointer
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

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Node
{
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val)
  {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    if (head == nullptr)
      return head;
    unordered_map<Node *, Node *> dict;
    Node *currNode = head;
    // put <original, copied> pair into dict, currNode->random 可能指向一个目前不存在的node
    while (currNode != nullptr)
    {
      dict[currNode] = new Node(currNode->val);
      currNode = currNode->next;
    }

    currNode = head;
    Node *copiedHead = dict[currNode];
    while (currNode != nullptr)
    {
      Node *copiedNode = dict[currNode];
      copiedNode->next = currNode->next != nullptr ? dict[currNode->next] : nullptr;
      copiedNode->random = currNode->random != nullptr ? dict[currNode->random] : nullptr;

      currNode = currNode->next;
    }

    return copiedHead;
  }

  /*
    HuaHua
    https://zxi.mytechroad.com/blog/hashtable/leetcode-138-copy-list-with-random-pointer/
  */
  Node *copyRandomList(Node *head)
  {
    if (!head)
      return head;

    unordered_map<Node *, Node *> m;
    Node *cur = m[head] = new Node(head->val);
    Node *ans = cur;

    while (head)
    {
      if (head->random)
      {
        auto it = m.find(head->random);
        if (it == end(m))
          it = m.emplace(head->random, new Node(head->random->val)).first;
        cur->random = it->second;
      }

      if (head->next)
      {
        auto it = m.find(head->next);
        if (it == end(m))
          it = m.emplace(head->next, new Node(head->next->val)).first;
        cur->next = it->second;
      }

      head = head->next;
      cur = cur->next;
    }

    return ans;
  }
};