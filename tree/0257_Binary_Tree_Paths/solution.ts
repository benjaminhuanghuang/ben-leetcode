import { TreeNode } from "../../common/TreeNode";

function binaryTreePaths(root: TreeNode | null): string[] {
  const res: string[] = [];
  if (root === null) return res;

  if (root.left === null && root.right === null) {
    res.push(root.val.toString());
  }
  if (root.left !== null) {
    for (const path of binaryTreePaths(root.left)) {
      res.push(`${root.val}->${path}`);
    }
  }
  if (root.right !== null) {
    for (const path of binaryTreePaths(root.right)) {
      res.push(`${root.val}->${path}`);
    }
  }

  return res;
}
