/*
2415. Reverse Odd Levels of Binary Tree

https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/
*/

import { TreeNode } from "../Common/TreeNode";

/*
    Approach: Level Order Traversal, 
    suppose the node values at level 3 are [2,1,3,4,7,11,29,18], should become [18,29,11,7,4,3,1,2].
*/
function reverseOddLevels(root: TreeNode | null): TreeNode | null {
  const queue: (TreeNode | null)[] = [root]; // Initialize a queue for level order traversal.
  let depth = 0; // Initialize tree depth.

  // Perform a level order traversal using a queue.
  while (queue.length !== 0) {
    const levelSize = queue.length; // Number of nodes at the current level.
    const currentLevelNodes: TreeNode[] = []; // Holds nodes of the current level if the level is odd.

    // Process nodes by their level.
    for (let i = 0; i < levelSize; i++) {
      const node = queue.shift();
      if (node) {
        // On odd levels, add the nodes to the currentLevelNodes array for later reversal.
        if (depth % 2 === 1) {
          currentLevelNodes.push(node);
        }

        // Enqueue child nodes for the next level.
        if (node.left) queue.push(node.left);
        if (node.right) queue.push(node.right);
      }
    }

    // If the current level is odd, reverse the values of nodes at this current level.
    if (depth % 2 === 1) {
      const middleIndex = currentLevelNodes.length >> 1; // Get the midpoint index. This is the Key of the solution.
      for (let i = 0; i < middleIndex; i++) {
        // Swap values between symmetric nodes.
        const mirrorIndex = currentLevelNodes.length - 1 - i;
        [currentLevelNodes[i].val, currentLevelNodes[mirrorIndex].val] = [
          currentLevelNodes[mirrorIndex].val,
          currentLevelNodes[i].val,
        ];
      }
    }

    // Increment depth after each level.
    depth++;
  }

  // Return the root of the modified tree.
  return root;
}
