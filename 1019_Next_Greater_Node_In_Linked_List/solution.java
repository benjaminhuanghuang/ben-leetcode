package cn.huang.leetcode;

import cn.huang.leetcode.common.ListNode;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/*
1019. Next Greater Node In Linked List

We are given a linked list with head as the first node.  Let's number the nodes in the list: node_1, node_2, node_3, ... etc.

Each node may have a next larger value: for node_i, next_larger(node_i) is the node_j.val such that j > i,
node_j.val > node_i.val, and j is the smallest possible choice.  If such a j does not exist, the next larger value is 0.

Return an array of integers answer, where answer[i] = next_larger(node_{i+1}).

Note that in the example inputs (not outputs) below, arrays such as [2,1,5] represent the serialization of a linked
list with a head node value of 2, second node value of 1, and third node value of 5.



Example 1:

Input: [2,1,5]
Output: [5,5,0]

Example 2:

Input: [2,7,4,3,5]
Output: [7,0,5,5,0]

Example 3:

Input: [1,7,5,1,9,2,5,1]
Output: [7,9,9,9,0,5,0,0]

 */
public class LC_1019_NextGreaterNodeInLinkedList {
    /*

        https://www.youtube.com/watch?v=e4BtnOVy0Gs
        Time Complexity O(N), Space complexity O(N)

        Monotonic stack : from top to bottom, elements are monotonically increasing
        [LC 739, LC 901]

     */
    public int[] nextLargerNodes(ListNode head) {
        List<Integer> nums = new ArrayList<>();

        while(head != null)
        {
            nums.add(head.val);
            head = head.next;
        }
        Stack<Integer> s = new Stack<>();
        int[] ans = new int[nums.size()];
        for(int i = nums.size() - 1; i >=0; i--)
        {
            while(!s.isEmpty() && s.peek() <= nums.get(i))
                s.pop();
            ans[i] = s.isEmpty() ? 0: s.peek();
            s.push(nums.get(i));
        }
        return ans;
    }
}
