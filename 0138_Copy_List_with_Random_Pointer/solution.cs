/*
138. Copy List with Random Pointer

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

*/

using System.Collections.Generic;

//* Definition for singly-linked list with a random pointer.
public class RandomListNode {
    public int label;
    public RandomListNode next, random;
    public RandomListNode(int x) { this.label = x; }
};

public class Solution138 {
    public RandomListNode CopyRandomList(RandomListNode head) {
        if (head == null) 
            return null;
        var dict = new Dictionary<RandomListNode, RandomListNode>();
        var currNode = head;
        // put <original, copied> pair into dict
        while (currNode != null)
        {
            dict.Add(currNode, new RandomListNode(currNode.label));
            currNode = currNode.next;
        }

        currNode = head;
        var copiedHead = dict[currNode];
        while (currNode != null)
        {
            var copiedNode = dict[currNode];
            copiedNode.next = currNode.next != null ? dict[currNode.next] : null;
            copiedNode.random = currNode.random != null ? dict[currNode.random] : null;

            currNode = currNode.next;
        }

        return copiedHead;
    }
}