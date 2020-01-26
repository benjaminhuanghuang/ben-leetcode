/*
951. Flip Equivalent Binary Trees

https://leetcode.com/problems/flip-equivalent-binary-trees/
 */

#include "common/TreeNode.h"

/*
  1：当前节点都为None，返回True；
  2：当前节点都不为None，此时若两个节点的值不相等，返回False，反之，递归到下一层，比较左右子结点，分为两种情况
      （左节点对左节点，右节点对右节点或者左节点对右节点，右节点对左节点），一种情况为True，就返回True；
  3：一个为None，一个不为None，返回False。
*/

class Solution
{
public:
  bool flipEquiv(TreeNode *root1, TreeNode *root2)
  {
    if (root1 == nullptr && root2 == nullptr)
      return true;
    else if (root1 != nullptr && root2 != nullptr)
      if (root1->val != root2->val)
        return false;
      else
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    else
      return false;
  }
};