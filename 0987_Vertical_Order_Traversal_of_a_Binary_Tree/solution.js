/*
987. Vertical Order Traversal of a Binary Tree

Level: Medium

https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree
*/

/*
  Solution: 

  https://www.youtube.com/watch?v=Nwz6hoqDi2w
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
 * @return {number[][]}
 */
var verticalTraversal = function(root) {
  const m = {};

  const dfs = (n, x ,y )=>{
    if((!n)) return;

    if(m[x]=== undefined){
      m[x] = {};
      m[x][y] = [n.val];  
    }
    else if(m[x][y]=== undefined){
      m[x][y] = [n.val];  
    }
    else{
      m[x][y].push(n.val);  
    }

    dfs(n.left, x -1, y+1);
    dfs(n.right, x +1, y+1);
  }

  dfs(root, 0 ,0);

  var keys= Object.keys(m).sort((a, b) => a-b);

  const res = [];

  for(let i =0 ;i < keys.length; i++)
  {
    const my = m[keys[i]];
    const yKeys = Object.keys(my).sort((a,b) => a -b);
    var tmp =[];
    for(let j =0;i < yKeys.length; j++){
      my[yKeys[j]].sort((a,b) => a-b);
      tmp = tmp.concat(my[yKeys[j]]);
    }
    res.push(tmp);
  }
  return res;
};


export { twoSum };