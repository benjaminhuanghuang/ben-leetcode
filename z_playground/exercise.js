/**
 * Definition for singly-linked list node.
 */
function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
function mergeKLists(lists) {
  // TODO: implement
  const heap = new MinHeap();
  for (const l of lists) {
    if (l) heap.push(l);
  }

  const dummy = new ListNode();
  let curr = dummy;

  while (heap.length() > 0) {
    const node = heap.pop();
    curr.next = node;
    curr = curr.next;
    if (node.next) heap.push(node.next);
  }

  return dummy.next;
}

class MinHeap {
  constructor() {
    this.heap = [];
  }

  push(val) {
    this.heap.push(val);
    // heapify up
    this.heapifyUp(this.heap.length - 1);
  }

  heapifyUp(i) {
    while (i > 0) {
      const parent = Math.floor((i - 1) / 2);
      if (this.heap[parent].val <= this.heap[i].val) break;

      this.swap(parent, i);
      i = parent;
    }
  }

  pop() {
    const val = this.heap[0];
    const last = this.heap.pop();
    if (this.heap.length > 0) {
      this.heap[0] = last;
      // heapyify down
      this.heapifyDown(0);
    }
    return val;
  }

  heapifyDown(i) {
    const n = this.heap.length;
    while (true) {
      let smallest = i;
      const left = 2 * i + 1;
      const right = 2 * i + 2;
      if (left < n && this.heap[left].val < this.heap[smallest].val) {
        smallest = left;
      }
      if (right < n && this.heap[right].val < this.heap[smallest].val) {
        smallest = right;
      }
      if (i === smallest) {
        break;
      }
      this.swap(i, smallest);
      i = smallest;
    }
  }

  length() {
    return this.heap.length;
  }
  swap(i, j) {
    [this.heap[i], this.heap[j]] = [this.heap[j], this.heap[i]];
  }
}
