/*
1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree

Level: Medium

https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree
*/

/*
  Solution: 
*/

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} original
 * @param {TreeNode} cloned
 * @param {TreeNode} target
 * @return {TreeNode}
 */

var getTargetCopy = function(original, cloned, target) {
  if (!original)
  return nullptr;
  if (original == target)
    return cloned;
  const l = getTargetCopy(original.left, cloned.left, target);
  const r = getTargetCopy(original.right, cloned.right, target);
  return l ? l : r;
};


export { getTargetCopy };