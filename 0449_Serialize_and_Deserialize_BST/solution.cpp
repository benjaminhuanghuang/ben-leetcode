/*
449. Serialize and Deserialize BST
https://leetcode.com/problems/serialize-and-deserialize-bst/
 */

#include <string>
#include <climits>

using namespace std;

#include "common/TreeNode.h"

class Codec
{
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    string s;
    serialize(root, s);
    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    int pos = 0;
    return deserialize(data, pos, INT_MIN, INT_MAX);
  }

private:
  void serialize(TreeNode *root, string &s)
  {
    if (!root)
      return;
    s.append(reinterpret_cast<const char *>(&root->val), sizeof(root->val));
    serialize(root->left, s);
    serialize(root->right, s);
  }

  TreeNode *deserialize(const string &s, int &pos, int curMin, int curMax)
  {
    if (pos >= s.size())
      return nullptr;
    int val = *reinterpret_cast<const int *>(s.data() + pos);
    if (val < curMin || val > curMax)
      return nullptr;
    pos += sizeof(val);
    TreeNode *root = new TreeNode(val);
    root->left = deserialize(s, pos, curMin, val);
    root->right = deserialize(s, pos, val, curMax);
    return root;
  }
};
