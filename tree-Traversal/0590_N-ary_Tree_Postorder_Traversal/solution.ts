/*
590. N-ary Tree Postorder Traversal

https://leetcode.com/problems/n-ary-tree-postorder-traversal/
*/

class _Node {
  val: number;
  children: _Node[];

  constructor(val?: number, children?: _Node[]) {
    this.val = val === undefined ? 0 : val;
    this.children = children === undefined ? [] : children;
  }
}

function postorder(root: _Node | null): number[] {
  const result: number[] = [];
  if (root === null) return result;

  function traverse(node: _Node | null) {
    if (node === null) return;
    for (let child of node.children) {
      traverse(child);
    }
    result.push(node.val); // Visit the node last
  }

  traverse(root);
  return result;
}

export {};
