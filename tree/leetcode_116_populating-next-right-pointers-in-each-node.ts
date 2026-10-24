/*
116. Populating Next Right Pointers in Each Node

https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
*/

class _Node {
  val: number;
  left: _Node | null;
  right: _Node | null;
  next: _Node | null;
  constructor(val?: number, left?: _Node, right?: _Node, next?: _Node) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
    this.next = next === undefined ? null : next;
  }
}

function connect(root: _Node | null): _Node | null {
  if (root === null) return root;
  const q: (_Node | null)[] = [];
  q.push(root);

  while (q.length > 0) {
    let size = q.length;
    let prev: _Node | null = null; // start of the level

    while (size-- > 0) {
      const curr = q.shift()!;
      if (prev !== null) {
        prev.next = curr;
      }
      prev = curr;

      if (curr.left !== null) {
        q.push(curr.left);
      }
      if (curr.right !== null) {
        q.push(curr.right);
      }
    }
  }
  return root;
}
export {};
