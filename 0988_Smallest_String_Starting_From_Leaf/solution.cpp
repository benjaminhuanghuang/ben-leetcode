/*
988. Smallest String Starting From Leaf
https://leetcode.com/problems/smallest-string-starting-from-leaf/
 */
#include <string>
using namespace std;

#include "common/TreeNode.h"
/*
https://zxi.mytechroad.com/blog/tree/leetcode-988-smallest-string-starting-from-leaf/
 */
class Solution_Err
{
public:
    string smallestFromLeaf(TreeNode *root)
    {
        if (!root)
            return "|"; // '|' > 'z'
        const char v = static_cast<char>('a' + root->val);
        if (!root->left && !root->right)
            return string(1, v);
        string l = smallestFromLeaf(root->left);
        string r = smallestFromLeaf(root->right);
        return min(l, r) + v;
    }
};

class Solution {
public:
    string findSmallestString(TreeNode* root, string curr) {
        if(!root)
            return "~";
        
        // add the current character to the string
        curr = string(1, 'a' + root->val) + curr;
        
        // recurse for left and right subtrees
        string left = findSmallestString(root->left, curr);
        string right = findSmallestString(root->right, curr);
        
        // when a leaf node is encountered, we just return the string from that 
        // till root, else we return the min of left and right
        // null node returns '~' which takes care of situations where
        // node has only one child
        return (left == right) && (left == "~") ? curr : min(left, right);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string curr;
        return findSmallestString(root, curr);
    }
};
