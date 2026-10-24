/*
716. Max Stack

https://leetcode.com/problems/max-stack/description/

top() operation must run in O(1) time
peekMax() 返回最大值 O(1)

[LinkedIn]
*/

/*
https://algo.monster/liteproblems/716

注意 MaxStack 是一个 同时需要“栈顺序”和“排序顺序” 的结构：
push / pop / top	必须符合栈顺序（LIFO）
peekMax / popMax	必须按值大小排序，并且在最大值里选“靠栈顶最近的”

比如：
push 顺序（栈）:   5 → 1 → 5 → 2 → 8 (top)
最大值顺序（升序）: 1, 2, 5, 5, 8

双向链表维护 栈顺序（push/pop/top），这是 popMax 做到O(1)的关键。
有序结构维护 max value 用于 peekMax/popMax
map 维护同值的所有节点列表，辅助 popMax 定位节点

每次 popMax 取 nodes[] 的 最后一个节点，保证离栈顶最近（满足题意）
*/

class ListNode {
  val: number;
  prev: ListNode | null;
  next: ListNode | null;

  constructor(val: number) {
    this.val = val;
    this.prev = null;
    this.next = null;
  }
}

class MaxStack {
  private head: ListNode | null = null; // bottom
  private tail: ListNode | null = null; // top

  // value -> list of nodes with that value
  private valueToNodes: Map<number, ListNode[]> = new Map();

  // sorted list of unique values
  private sortedValues: number[] = [];

  constructor() {
    // no-op (values already initialized)
  }

  push(x: number): void {
    const newNode = new ListNode(x);

    // Add to linked list tail
    if (!this.tail) {
      this.head = this.tail = newNode;
    } else {
      this.tail.next = newNode;
      newNode.prev = this.tail;
      this.tail = newNode;
    }

    // Add to map
    if (!this.valueToNodes.has(x)) {
      this.valueToNodes.set(x, []);

      // Insert x into sortedValues (unique values only)
      const idx = this.binarySearchInsert(this.sortedValues, x);
      this.sortedValues.splice(idx, 0, x);
    }

    this.valueToNodes.get(x)!.push(newNode);
  }

  pop(): number {
    const topNode = this.tail!;
    const topValue = topNode.val;

    // Remove from linked list
    if (topNode.prev) {
      topNode.prev.next = null;
      this.tail = topNode.prev;
    } else {
      this.head = this.tail = null;
    }

    // Remove from map
    const arr = this.valueToNodes.get(topValue)!;
    arr.pop();
    // Clean up if no more nodes with this value
    if (arr.length === 0) {
      this.valueToNodes.delete(topValue);
      const idx = this.sortedValues.indexOf(topValue);
      this.sortedValues.splice(idx, 1);
    }

    return topValue;
  }

  top(): number {
    return this.tail!.val;
  }

  peekMax(): number {
    return this.sortedValues[this.sortedValues.length - 1];
  }

  popMax(): number {
    const maxValue = this.sortedValues[this.sortedValues.length - 1];
    const nodes = this.valueToNodes.get(maxValue)!;

    // Last node with this value = the one closest to the top
    const maxNode = nodes[nodes.length - 1];

    // Remove from linked list
    if (maxNode.prev) {
      maxNode.prev.next = maxNode.next;
    } else {
      this.head = maxNode.next;
    }

    if (maxNode.next) {
      maxNode.next.prev = maxNode.prev;
    } else {
      this.tail = maxNode.prev;
    }

    // Remove from map
    nodes.pop();
    if (nodes.length === 0) {
      this.valueToNodes.delete(maxValue);
      this.sortedValues.pop();
    }

    return maxValue;
  }

  private binarySearchInsert(arr: number[], target: number): number {
    let left = 0;
    let right = arr.length;

    while (left < right) {
      const mid = Math.floor((left + right) / 2);
      if (arr[mid] < target) left = mid + 1;
      else right = mid;
    }

    return left;
  }
}
