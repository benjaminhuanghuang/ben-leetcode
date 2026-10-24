/*
138. Copy List with Random Pointer
https://leetcode.com/problems/copy-list-with-random-pointer/

- 133. Clone Graph
*/

class _Node {
  val: number;
  next: _Node | null;
  random: _Node | null;

  constructor(val?: number, next?: _Node, random?: _Node) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
    this.random = random === undefined ? null : random;
  }
}

/*
    This method involves creating a deep copy of the linked list by creating a new node for each node in the original list.
    We then iterate through the list again to assign the random pointer of each new node.
*/
function copyRandomList(head: _Node | null): _Node | null {
  if (!head) {
    return null;
  }

  let map = new Map();
  let current = head;

  // Create new nodes and store them in a map with the original node as the key
  while (current) {
    map.set(current, new _Node(current.val));
    current = current.next!;
  }

  current = head;
  // set the next and random pointers of the new nodes
  while (current) {
    map.get(current).next = current.next ? map.get(current.next) : null;
    map.get(current).random = current.random ? map.get(current.random) : null;
    current = current.next!;
  }

  return map.get(head);
}
