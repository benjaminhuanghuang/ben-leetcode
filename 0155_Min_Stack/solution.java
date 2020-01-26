package cn.huang.leetcode;

import basic.ArrayListDemo;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/*
155. Min Stack
 */
public class LC_0155_MinStack {
    class MinStack {
        private Stack<Integer> stack = new Stack<>();
        private Stack<Integer> minStack = new Stack<>();

        /** initialize your data structure here. */
        public MinStack() {
        }

        public void push(int x) {
            //如果压入栈顶的元素比最小值小，那么最小值栈压入当前值，否则压入最小值栈顶元素。
            if (minStack.isEmpty() || x <= minStack.peek())
                minStack.push(x);    // push the min value
            else
                minStack.push(minStack.peek());// keeping push the min value
            stack.push(x);
        }

        public void pop() {
            //同时删除最小值栈顶元素
            minStack.pop();
            stack.pop();
        }

        public int top() {
            return stack.peek();
        }

        public int getMin() {
            return minStack.peek();

        }
    }

}
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */