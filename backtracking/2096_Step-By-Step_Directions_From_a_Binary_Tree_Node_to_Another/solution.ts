/*
2096. Step-By-Step Directions From a Binary Tree Node to Another

https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
*/

import { TreeNode } from "../Common/TreeNode";

/*
To case where path(start, end) goes through the root. 
It can be split this into
path(start, root) + path(root, end). 

We can perform a DFS (depth first search) to get path(root, end). This path consists of 'L's and 'R's. We can do another DFS to get
path(root, start). Replacing the 'L's and 'R's of path(root, start) with 'U's gives us
path(start, root). 

Replace all node value from start to LCA to U in start path 

Now we can concatenate path(start, root) and path(root, end) to get the
answer.

*/

/*
    In JavaScript, strings are immutable and are passed by value, not by reference. 
    So, we need to use an object {value: string} to pass the answer string by reference.
*/
function getPath(
  cur: TreeNode | null,
  targetValue: number,
  path: string[],
  ans: { value: string }
): void {
  if (!cur) return;
  if (cur.val === targetValue) ans.value = path.join("");

  path.push("L");
  getPath(cur.left, targetValue, path, ans);

  path[path.length - 1] = "R";
  getPath(cur.right, targetValue, path, ans);

  path.pop(); // backtrack
}

function getDirections(
  root: TreeNode | null,
  startValue: number,
  destValue: number
): string {
  let tmpPath: string[] = [];
  let startPath: { value: string } = { value: "" };
  let destPath: { value: string } = { value: "" };

  getPath(root, startValue, tmpPath, startPath);
  getPath(root, destValue, tmpPath, destPath);

  let i = 0;
  const minLen = Math.min(startPath.value.length, destPath.value.length);
  while (i < minLen && startPath.value[i] === destPath.value[i]) {
    i++;
  }

  const upMoves = "U".repeat(startPath.value.length - i);
  const downMoves = destPath.value.substring(i);

  return upMoves + downMoves;
}
