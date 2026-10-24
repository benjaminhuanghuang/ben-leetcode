package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;

/*
138. Copy List with Random Pointer  [133]

 A linked list is given such that each node contains an additional random pointer which could point
  to any node in the list or null.

Return a deep copy of the list.


 */
public class LC_0138_CopyListwithRandomPointer {
    class RandomListNode {
        int label;
        RandomListNode next, random;

        RandomListNode(int x) {
            this.label = x;
        }
    }

    public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null)
            return null;

        Map<RandomListNode, RandomListNode> visited = new HashMap<RandomListNode, RandomListNode>();
        RandomListNode currNode = head;

        // copy all nodes without connect
        // put <original, copied> pair into dict
        while (currNode != null)
        {
            visited.put(currNode, new RandomListNode(currNode.label));
            currNode = currNode.next;
        }

        currNode = head;
        RandomListNode copiedHead = visited.get(currNode);

        while (currNode != null)
        {
            RandomListNode copiedNode = visited.get(currNode);

            copiedNode.next = currNode.next != null ? visited.get(currNode.next) : null;
            copiedNode.random = currNode.random != null ? visited.get(currNode.random) : null;

            currNode = currNode.next;
        }

        return copiedHead;
    }
}
