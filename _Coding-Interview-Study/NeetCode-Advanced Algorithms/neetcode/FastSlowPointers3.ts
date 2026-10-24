/*
Q: Determine if a linked list has a cycle  and return the beginning of the cycle if it exists.
*/

/* Time: O(n), Space: O(1)

  a = 头节点到环入口的距离
  b = 环入口到相遇点的距离
  c = 相遇点再走到环入口的距离  
  环长 = b + c

    fast: a + n(b+c) + b
    slow: a + b
    
    The answer is a 

    a + n(b+c) + b = 2(a + b)
    a = (n-1)(b+c) + c
    a 等于 若干个完整环 + c
    从相遇点走 a 步，一定能到达环入口。
 */
function cycleStart(head: ListNode | null): ListNode | null {
  let slow = head;
  let fast = head;

  while (fast !== null && fast.next !== null) {
    slow = slow!.next;
    fast = fast.next.next;
    // 如果链表有环，快慢指针最终会在环内相遇。
    if (slow === fast) {
      break; // fast and slow meet, there is a cycle
    }
  }

  // if there is no cycle, return null
  if (fast === null || fast.next === null) {
    return null;
  }

  // 从 head 到环起点的距离 = 从相遇点沿环继续走到环起点的距离
  let slow2 = head;
  while (slow !== slow2) {
    slow = slow!.next;
    slow2 = slow2!.next;
  }

  return slow;
}
