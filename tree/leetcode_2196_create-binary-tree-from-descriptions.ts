/*
2196. Create Binary Tree From Descriptions

https://leetcode.com/problems/create-binary-tree-from-descriptions/
*/
import { TreeNode } from "../Common/TreeNode";

function createBinaryTree(descriptions: number[][]): TreeNode | null {
  const hasParent: Set<number> = new Set();
  // key: parentId, value: {left: childId, right: childId}
  const children: Map<number, { left: number; right: number }> = new Map();

  for (const d of descriptions) {
    //descriptions[i] = [parenti, childi, isLefti]
    hasParent.add(d[1]);

    if (!children.has(d[0])) {
      children.set(d[0], { left: 0, right: 0 });
    }

    if (d[2]) {
      children.get(d[0])!.left = d[1];
    } else {
      children.get(d[0])!.right = d[1];
    }
  }

  // Find the root
  let root: number = -1;
  for (const d of descriptions) {
    if (!hasParent.has(d[0])) {
      root = d[0];
      break;
    }
  }

  const build = (cur: number): TreeNode | null => {
    if (!cur) return null;
    const child = children.get(cur) || { left: 0, right: 0 };
    return new TreeNode(cur, build(child.left), build(child.right));
  };

  return build(root);
}
