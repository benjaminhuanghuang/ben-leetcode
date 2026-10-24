/*
117. Populating Next Right Pointers in Each Node II

https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
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
  if (root === null) {
    return null;
  }

  let queue: _Node[] = [];
  queue.push(root);

  while (queue.length > 0) {
    let size = queue.length;

    for (let i = 0; i < size; i++) {
      let node = queue.shift() as _Node;

      // connect the nodes in the same level
      if (i < size - 1) {
        node.next = queue[0];
      }

      // push the children nodes into the queue
      if (node.left !== null) {
        queue.push(node.left);
      }

      if (node.right !== null) {
        queue.push(node.right);
      }
    }
  }

  return root;
}

export {};
