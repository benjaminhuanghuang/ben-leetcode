/*
1339. Maximum Product of Splitted Binary Tree

Level: Medium

https://leetcode.com/problems/maximum-product-of-splitted-binary-tree
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
 * @return {number}
 */
var maxProduct = function(root) {
    let res = 0;
    const getSum = (node) =>{
      if(!node){
        return 0;
      }
      const left = getSum(node.left);
      const right = getSum(node.right);
      return left + right + node.val;
    }

    const totalSum = get(root);
    const split = (node) =>{
      if(!node){
        return 0;
      }
      const left = split(node.left);
      const right = split(node.right);
      res = Math.max(res, left * (totalSum - left));
      res = Math.max(res, right * (totalSum - right));
      return left + right + node.val;
    }
    split(root);

    return res % (1e9+7);
};


export { twoSum };