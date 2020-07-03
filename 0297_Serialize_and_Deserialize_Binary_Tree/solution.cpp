/*
297. Serialize and Deserialize Binary Tree

Level: Hard

https://leetcode.com/problems/serialize-and-deserialize-binary-tree

- 449. Serialize and Deserialize BST
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <sstream> 
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  
  http://zxi.mytechroad.com/blog/tree/leetcode-297-serialize-and-deserialize-binary-tree/

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
  ASCII
  pre-order 
*/

class Codec
{
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    ostringstream out;
    write(root, out);
    return out.str();
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    istringstream in(data);
    return read(in);
  }

private:
  void write(TreeNode *root, ostringstream &out)
  {
    if (!root)
    {
      out << "# ";
      return;
    }
    out << root->val << " ";
    write(root->left, out);
    write(root->right, out);
  }

  TreeNode *read(istringstream &in)
  {
    string val;
    in >> val;
    if (val == "#")
      return nullptr;
    TreeNode *root = new TreeNode(stoi(val));
    root->left = read(in);
    root->right = read(in);
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));