/*
23. Merge k Sorted Lists

https://leetcode.com/problems/merge-k-sorted-lists/
*/
import { ListNode } from "../Common/ListNode";

/*
// 最简单的办法就是扫一遍k个链表的开头，哪个最小就把它移除，加入到结果链表中。这样时间复杂度是kn
*/

// 将k个链表分为两个一组，组内进行merge。形成一个新的链表集合，大小为(k + 1)/2。继续两个一组merge，
// 这样下去一共会进行logk次merge，最后merge成为一个链表。总的时间复杂度是nlogk
function mergeKLists(lists: ListNode[]): ListNode | null {
  const len = lists.length;
  if (len === 0) return null;
  if (len === 1) return lists[0];
  if (len === 2) return mergeTwoLists(lists[0], lists[1]);

  const mid = Math.floor(len / 2);
  const left = mergeTwoListsHelper(lists, 0, mid);
  const right = mergeTwoListsHelper(lists, mid + 1, len - 1);

  return mergeTwoLists(left, right);
}

function mergeTwoListsHelper(
  lists: ListNode[],
  left: number,
  right: number
): ListNode | null {
  if (left > right) return null;
  if (left === right) return lists[left];

  const mid = Math.floor((right - left) / 2) + left;
  const leftLists = mergeTwoListsHelper(lists, left, mid);
  const rightLists = mergeTwoListsHelper(lists, mid + 1, right);

  return mergeTwoLists(leftLists, rightLists);
}

function mergeTwoLists(
  l1: ListNode | null,
  l2: ListNode | null
): ListNode | null {
  const dummyHead = new ListNode(-1);
  let curr = dummyHead;

  while (l1 !== null && l2 !== null) {
    if (l1.val < l2.val) {
      curr.next = l1;
      l1 = l1.next;
    } else {
      curr.next = l2;
      l2 = l2.next;
    }
    curr = curr.next;
  }

  if (l1 !== null) curr.next = l1;
  if (l2 !== null) curr.next = l2;

  return dummyHead.next;
}
