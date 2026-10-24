/*
173. Binary Search Tree Iterator
https://leetcode.com/problems/binary-search-tree-iterator/
 */

#include <vector>
#include <stack>
using namespace std;

#include "common/TreeNode.h"

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while(root != NULL )
        {
            s.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        int result = 0;
        if(!s.empty())
        {
            TreeNode* node = s.top();
            result = node->val;
            s.pop();
            node = node->right;
            while(node != nullptr)
            {
                s.push(node);
                node = node->left;
            }
        }
        return result;
    }
    private:
    stack<TreeNode*> s;
};
