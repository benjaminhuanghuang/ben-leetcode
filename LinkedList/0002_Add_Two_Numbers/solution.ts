/*
2. Add Two Numbers
https://leetcode.com/problems/add-two-numbers/description/
*/

import { ListNode } from "../Common/ListNode";

function addTwoNumbers(
  l1: ListNode | null,
  l2: ListNode | null
): ListNode | null {
  let carry = 0;
  let dummy = new ListNode();
  let l = dummy;

  while (l1 || l2) {
    const localSum = getNodeValue(l1) + getNodeValue(l2) + carry;
    const digit = localSum % 10;
    carry = localSum >= 10 ? 1 : 0; // Math.floor(localSum /10);
    l.next = new ListNode(digit);
    l = l.next;
    if (l1) l1 = l1.next;
    if (l2) l2 = l2.next;
  }

  if (carry > 0) {
    l.next = new ListNode(carry);
  }
  return dummy.next;
}

function getNodeValue(node: ListNode | null): number {
  return node ? node.val : 0;
}

function addTwoNumbers1(
  l1: ListNode | null,
  l2: ListNode | null
): ListNode | null {
  let carry = 0;
  let dummy = new ListNode();
  let l = dummy;

  while (l1 && l2) {
    const localSum = l1.val + l2.val + carry;
    const digit = localSum % 10;
    carry = localSum >= 10 ? 1 : 0; // Math.floor(localSum /10);
    l.next = new ListNode(digit);
    l = l.next;
    l1 = l1.next;
    l2 = l2.next;
  }

  while (l1) {
    const localSum = l1.val + carry;
    const digit = localSum % 10;
    carry = Math.floor(localSum / 10);
    l.next = new ListNode(digit);
    l = l.next;
    l1 = l1.next;
  }

  while (l2) {
    const localSum = l2.val + carry;
    const digit = localSum % 10;
    carry = Math.floor(localSum / 10);
    l.next = new ListNode(digit);
    l = l.next;
    l2 = l2.next;
  }
  if (carry > 0) {
    l.next = new ListNode(carry);
  }
  return dummy.next;
}
