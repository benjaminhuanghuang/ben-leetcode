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
/*
  每个节点当值需要的空间：负数最小为 -2^31 = -2147483648 需要11个字符，每个字符一个字节，
  如果使用binary， 每个节点只需要4个bytes
*/

class Codec {
public:
 
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }
 
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
private:
    enum STATUS {
        ROOT_NULL = 0x0,
        ROOT = 0x1,
        LEFT = 0x2,
        RIGHT = 0x4
    };
    
    void serialize(TreeNode* root, ostringstream& out) {
        char status = 0;
        if (root) status |= ROOT;
        if (root && root->left) status |= LEFT;
        if (root && root->right) status |= RIGHT;
        out.write(&status, sizeof(char));        
        if (!root) return;
        out.write(reinterpret_cast<char*>(&(root->val)), sizeof(root->val));
        if (root->left) serialize(root->left, out);
        if (root->right) serialize(root->right, out);
    }
    
    TreeNode* deserialize(istringstream& in) {
        char status;
        in.read(&status, sizeof(char));
        if (!status & ROOT) return nullptr;
        auto root = new TreeNode(0);
        in.read(reinterpret_cast<char*>(&root->val), sizeof(root->val));        
        root->left = (status & LEFT) ? deserialize(in) : nullptr;
        root->right = (status & RIGHT) ? deserialize(in) : nullptr;
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));