/*
	255. Verify Preorder Sequence in Binary Search Tree
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary 
search tree.

You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity?

*/
using System.Collections.Generic;

public class Solution255 {
    public bool verifyPreorder(int[] preorder) {
        int low = int.MinValue;
        Stack<int> stack = new Stack<int>();
        foreach(int i in preorder) {
            if(i < low)
                return false;
            while(stack.Count > 0 && i > stack.Peek())
                low = stack.Pop();
            stack.Push(i);
        }
        
        return true;
    }

    public bool verifyPreorder_2(int[] preorder) {
        int low = int.MinValue, index = -1;
        foreach(int i in preorder) {
            if(i < low)
                return false;
            while(index >= 0 && i > preorder[index])
                low = preorder[index--];
            preorder[++index] = i;
        }
        
        return true;
    }
}