/*
865. Smallest Subtree with all the Deepest Nodes

https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

[Meta]

*/

import { TreeNode } from "../Common/TreeNode";

/*
https://www.youtube.com/watch?v=q1zk8vZIDw0 (HuaHua)

Compare the depth of the left and right subtree of the current node.

Time complexity: O(n)
Space complexity: O(n)
*/
function subtreeWithAllDeepest(root: TreeNode | null): TreeNode | null {
  return depth(root)[1];
}

function depth(root: TreeNode | null): [number, TreeNode | null] {
  if (root === null) {
    return [-1, null];
  }

  const [depthL, lNode] = depth(root.left);
  const [depthR, rNode] = depth(root.right);

  if (depthL === depthR) {
    return [depthL + 1, root];
  } else if (depthL > depthR) {
    return [depthL + 1, lNode];
  } else {
    return [depthR + 1, rNode];
  }
}
