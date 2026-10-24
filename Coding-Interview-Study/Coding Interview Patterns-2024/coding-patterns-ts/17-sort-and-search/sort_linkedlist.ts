class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val ?? 0;
    this.next = next ?? null;
  }
}

function sortLinkedList(head: ListNode | null): ListNode | null {
  // Base case: empty or single node
  if (!head || !head.next) return head;

  // Split the list into two halves
  const secondHead = splitList(head);

  // Recursively sort both halves
  const firstHalfSorted = sortLinkedList(head);
  const secondHalfSorted = sortLinkedList(secondHead);

  // Merge the two sorted halves
  return merge(firstHalfSorted, secondHalfSorted);
}

// Split linked list into two halves
function splitList(head: ListNode): ListNode | null {
  let slow: ListNode = head;
  let fast: ListNode = head;

  while (fast.next && fast.next.next) {
    slow = slow.next!;
    fast = fast.next.next;
  }

  const secondHead = slow.next;
  slow.next = null; // break the list
  return secondHead;
}

// Merge two sorted linked lists
function merge(l1: ListNode | null, l2: ListNode | null): ListNode | null {
  const dummy = new ListNode(0);
  let tail = dummy;

  while (l1 && l2) {
    if (l1.val < l2.val) {
      tail.next = l1;
      l1 = l1.next;
    } else {
      tail.next = l2;
      l2 = l2.next;
    }
    tail = tail.next;
  }

  // Append remaining nodes
  tail.next = l1 || l2;

  return dummy.next;
}

/*
Time complexity: O(n log n), where n is the number of nodes in the linked list. 
This is because we are performing a merge sort, which divides the list in half (log n divisions) and merges them back together (O(n) work) at each level.

Space complexity: O(log n) due to the recursion stack used for the divide step of the merge sort.
*/
