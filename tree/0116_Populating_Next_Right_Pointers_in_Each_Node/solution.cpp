/*
116. Populating Next Right Pointers in Each Node

Level: Medium

https://leetcode.com/problems/populating-next-right-pointers-in-each-node
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
*/

// Definition for a Node.
class Node
{
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
  Node *connect(Node *root)
  {
    if (root == nullptr)
      return root;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
      int size = q.size();
      Node *prev = nullptr;
      while (size--)
      {
        Node *curr = q.front();
        q.pop();
        if (prev)
        {
          prev->next = curr;
        }
        prev = curr;
        if (curr->left)
        {
          q.push(curr->left);
        }
        if (curr->right)
        {
          q.push(curr->right);
        }
      }
    }
    return root;
  }
};
/*
https://www.youtube.com/watch?v=YNu143ZN4qU

Time complexity O(N)   每个node 访问一次
Space complexity O(logN)  height of tree
*/
class Solution_HuaHua
{
public:
  Node *connect(Node *root)
  {
    if (!root || !root->left) 
      return root;
    root->left->next = root->right;

    if(root->next)
    {
      root->right->next = root->next->left;
    }
    connect(root->left);
    connect(root->right);
  }
};


class Solution_2
{
public:
  Node *connect(Node *root)
  {
    if (root == NULL)
      return NULL;
    helperFunction(root, NULL);
    return root;
  }

  void helperFunction(Node *curr, Node *next)
  {
    if (curr == NULL)
      return;
    curr->next = next;
    helperFunction(curr->left, curr->right);
    helperFunction(curr->right, next ? next->left : NULL);
  }
};