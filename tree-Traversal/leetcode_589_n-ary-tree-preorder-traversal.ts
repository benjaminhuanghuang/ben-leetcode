/*
589. N-ary Tree Preorder Traversal

https://leetcode.com/problems/n-ary-tree-preorder-traversal/
*/

class _Node {
  val: number;
  children: _Node[];

  constructor(val?: number, children?: _Node[]) {
    this.val = val === undefined ? 0 : val;
    this.children = children === undefined ? [] : children;
  }
}

function preorder(root: _Node | null): number[] {
  const result: number[] = [];
  if (root === null) return result;

  function traverse(node: _Node | null) {
    if (node === null) return;
    result.push(node.val); // Visit the node first
    for (let child of node.children) {
      traverse(child);
    }
  }

  traverse(root);
  return result;
}

export {};
