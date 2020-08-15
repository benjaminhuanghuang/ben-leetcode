/*
1145. Binary Tree Coloring Game

Level: Medium

https://leetcode.com/problems/binary-tree-coloring-game
*/

/*
  Solution: 
*/

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} n
 * @param {number} x
 * @return {boolean}
 */
var btreeGameWinningMove = function (root, n, x) {
  let left, right;
  const red = x;

  const dfs = (node) => {
    if (!node) {
      return 0;
    }
    const l = dfs(node.left);
    const r = dfs(node.right);
    if (node.val == red) {
      left = l;
      right = r;
    }
    return l + r + 1;
  };
  dfs(root);
  
  return Math.max(Math.max(left, right), n - left - right - 1) > n /2 ;
};

export { btreeGameWinningMove };
