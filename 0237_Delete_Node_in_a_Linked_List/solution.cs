/*
237. Delete Node in a Linked List

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list 
should become 1 -> 2 -> 4 after calling your function.

注意！如果node是list中的最后一个node，此题无解
*/

public class Solution237 {
    public void DeleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
