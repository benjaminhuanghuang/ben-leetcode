/*
430. Flatten a Multilevel Doubly Linked List

https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
*/

class _Node {
  val: number;
  prev: _Node | null;
  next: _Node | null;
  child: _Node | null;

  constructor(val?: number, prev?: _Node, next?: _Node, child?: _Node) {
    this.val = val === undefined ? 0 : val;
    this.prev = prev === undefined ? null : prev;
    this.next = next === undefined ? null : next;
    this.child = child === undefined ? null : child;
  }
}

function flatten(head: _Node | null): _Node | null {
  if (head === null) {
    return head;
  }

  let cur: _Node | null = head;
  while (cur !== null) {
    if (cur.child === null) {
      cur = cur.next;
      continue;
    }
    //  Just need to process the child node
    // find the tail of the child node, and link it to the next node
    let child: _Node | null = cur.child;
    let childTail: _Node | null = child;
    while (childTail!.next !== null) {
      childTail = childTail!.next;
    }

    cur.child = null;
    child!.prev = cur;
    childTail!.next = cur.next;
    if (cur.next !== null) {
      cur.next.prev = childTail;
    }
    cur.next = child;
    cur = cur.next;
  }

  return head;
}

export {};
