import { ListNode } from "../../common/ListNode";

function deleteDuplicates(head: ListNode | null): ListNode | null {
  let curr: ListNode | null = head;

  while (curr && curr.next) {
    if (curr.next.val === curr.val) {
      curr.next = curr.next.next;
    } else {
      curr = curr.next;
    }
  }

  return head;
}
