/*
117. Populating Next Right Pointers in Each Node II

Level: Medium

https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii
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
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


/*
https://www.cnblogs.com/grandyang/p/4290148.html

原本的完全二叉树的条件不再满足，但是整体的思路还是很相似，仍然有递归和非递归的解法。
这里由于子树有可能残缺，故需要平行扫描父节点同层的节点，找到他们的左右子节点

*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        // 平行扫描父节点同层的节点
        Node *p = root->next;
        while (p) {
            if (p->left) {
                p = p->left;
                break;
            }
            if (p->right) {
                p = p->right;
                break;
            }
            p = p->next;
        }
        if (root->right) root->right->next = p; 
        if (root->left) root->left->next = root->right ? root->right : p; 
        connect(root->right);
        connect(root->left);
        return root;
    }
};

/*

https://www.cnblogs.com/grandyang/p/4290148.html

题目说只能使用constant space，

*/
class Solution {
public:
    Node* connect(Node* root) {
       Node *dummy = new Node(0, NULL, NULL, NULL), *cur = dummy, *head = root;
        while (root) {
            if (root->left) {
                cur->next = root->left;
                cur = cur->next;
            }
            if (root->right) {
                cur->next = root->right;
                cur = cur->next;
            }
            root = root->next;
            if (!root) {
                cur = dummy;
                root = dummy->next;
                dummy->next = NULL;
            }
        }
        return head; 
    }
};