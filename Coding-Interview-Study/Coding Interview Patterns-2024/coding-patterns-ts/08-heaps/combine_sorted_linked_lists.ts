// Definition for singly-linked list node
export class ListNode {
  val: number;
  next: ListNode | null;

  constructor(val: number, next: ListNode | null = null) {
    this.val = val;
    this.next = next;
  }
}

// Merge k sorted linked lists
export function combine_sorted_linked_lists(
  lists: Array<ListNode | null>
): ListNode | null {
  // Min-heap comparing node values
  const heap = new MinHeap<ListNode>((a, b) => a.val < b.val);

  // Push the head of each non-empty list into heap
  for (const head of lists) {
    if (head) heap.push(head);
  }

  // Dummy node for result list
  const dummy = new ListNode(-1);
  let curr = dummy;

  // Extract min and push next nodes
  while (!heap.isEmpty()) {
    const smallestNode = heap.pop()!;
    curr.next = smallestNode;
    curr = curr.next;
    // If there is a next node, push it into the heap
    if (smallestNode.next) {
      heap.push(smallestNode.next);
    }
  }

  return dummy.next;
}

/*
Time complexity: The time complexity of combine_sorted_linked_lists is O(n * log(k)), where n
denotes the total number of nodes across the linked lists. Here's why:
• It takes O(k log(k)) time to create the heap initially because we insert k nodes into the heap
one by one.
• Then, for all n nodes, we perform a push and pop operation on the heap, each taking O(log(k))
time.
This results in a total time complexity of O(k log(k)) + n • O(log(k)) = O(n log(k)).

Space complexity: The space complexity is O(k) because the heap stores up to one node from
each of the k linked lists at any time.
*/
