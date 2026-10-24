/*
897. Increasing Order Search Tree

https://leetcode.com/problems/increasing-order-search-tree/

Conver BST to a 右孩链表
*/

import { TreeNode } from "../Common/TreeNode";

/*
Approach: Inorder Traversal
 
Time Complexity: O(n)
 */
function increasingBST(root: TreeNode | null): TreeNode | null {
  const dummy = new TreeNode();
  let cur = dummy;

  function inorder(node: TreeNode | null): void {
    if (!node) {
      return;
    }

    inorder(node.left);

    cur.right = node;
    node.left = null;
    cur = node;

    inorder(node.right);
  }

  inorder(root);

  return dummy.right;
}
