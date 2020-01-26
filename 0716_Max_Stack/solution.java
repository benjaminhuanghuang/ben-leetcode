package cn.huang.leetcode;

import java.util.Stack;

/*
716. Max Stack

Design a max stack that supports push, pop, top, peekMax and popMax.



push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.


Example 1:

MaxStack stack = new MaxStack();
stack.push(5);
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5


Note:

-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.

 */
public class LC_0716_MaxStack {
    class MaxStack {
        private Stack<Integer> stack;
        private Stack<Integer> maxStack;

        /**
         * initialize your data structure here.
         */
        public MaxStack() {
            stack = new Stack<>();
            maxStack = new Stack<>();
        }

        public void push(int x) {
            int max = maxStack.empty() ? x : Math.max(maxStack.peek(), x);
            stack.push(x);
            maxStack.push(max);
        }

        public int pop() {
            maxStack.pop();
            return stack.pop();
        }

        public int top() {
            return stack.peek();
        }

        public int peekMax() {
            return maxStack.peek();
        }

        /*
            pop the max value
         */
        public int popMax() {
            int target = maxStack.peek();
            Stack<Integer> tmp = new Stack<>();

            while (stack.peek() != target) {
                tmp.push(stack.pop());
                maxStack.pop();
            }

            stack.pop();    // pop the max value
            maxStack.pop();

            while (!tmp.empty()) {
                push(tmp.pop());
            }

            return target;
        }
    }
}
