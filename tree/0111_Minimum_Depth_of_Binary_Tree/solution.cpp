#include "common/TreeNode.h"

#include <algorithm>
#include <climits>
using namespace std;

class Solution_Wrong
{
public:
    /*
    The minimum depth is the number of nodes along the shortest path from the root 
    node down to the nearest leaf node.
     */
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        int l = root->left ? minDepth(root->left) : INT_MAX;
        int r = root->right ? minDepth(root->right) : INT_MAX;
        return min(l, r) + 1;
    }
};