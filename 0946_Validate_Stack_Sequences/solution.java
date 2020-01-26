package cn.huang.leetcode;

import java.util.Stack;

/*

946. Validate Stack Sequences

Given two sequences pushed and popped with distinct values, return true if and only if this could have been the
result of a sequence of push and pop operations on an initially empty stack.
 */
public class LC_0946_ValidateStackSequences {

    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> s = new Stack<>();
        if (pushed.length == 0 && popped.length == 0)
            return true;
        if (pushed.length == 0 || popped.length == 0)
            return false;

        s.push(pushed[0]);
        int i = 1, j = 0;
        while (true) {
            if (s.empty()) {
                if (i < pushed.length) {
                    s.push(pushed[i]);
                    ++i;
                } else
                    return false;
            }
            if (s.peek() == popped[j]) {
                s.pop();
                ++j;
            } else {
                if (i < pushed.length) {
                    s.push(pushed[i]);
                    ++i;
                } else
                    return false;
            }
            if (j == popped.length)
                return true;
            //
        }
    }

    /*
    Push element from |pushed sequence| onto stack s one by one and pop when top of the stack s is equal the current element in the |popped sequence|.
     */
    public boolean validateStackSequences_better(int[] pushed, int[] popped) {
        Stack<Integer> s = new Stack<>();
        if (pushed.length == 0 && popped.length == 0)
            return true;
        if (pushed.length == 0 || popped.length == 0)
            return false;
        int i = 0;
        for(int num:pushed)
        {
            s.push(num);
            while(!s.isEmpty() && s.peek() == popped[i])
            {
                s.pop();
                i++;
            }
        }
        return i == popped.length;
    }
}
