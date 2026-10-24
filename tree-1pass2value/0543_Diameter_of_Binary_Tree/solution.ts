/*
543. Diameter of Binary Tree

https://leetcode.com/problems/diameter-of-binary-tree/
*/

import { TreeNode } from "../Common/TreeNode";

/*
    对根节点递归计算左右子树的Diameter，通过和类内的变量 diameter 进行比较，保存较大值。
    在每一次递归结束后，返回这棵子树的深度，根节点获取了maxDepthLeft and maxDepthRight后，
    将二者相加就是cross root 的Diameter。
    注意审题！length is edges！

    Time complexity: O(n)—每个node过一遍;
    Space complexity: O(H)； worst case is O(N), balanced O(log(N))
*/
function diameterOfBinaryTree(root: TreeNode | null): number {
  if (root === null) return 0;
  let diameter = 0;

  function getMaxDepth(node: TreeNode | null): number {
    if (node === null) return 0;
    const depthLeft = getMaxDepth(node.left);
    const depthRight = getMaxDepth(node.right);

    // get the max diameter cross the root
    // diameter = depthLeft + depthRight
    diameter = Math.max(depthLeft + depthRight, diameter);
    return Math.max(depthLeft, depthRight) + 1;
  }

  getMaxDepth(root);
  return diameter;
}
