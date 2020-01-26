package cn.huang.leetcode;

import java.util.Stack;

/*
232. Implement Queue using Stacks

 */
public class LC_0232_ImplementQueueusingStacks {
    class MyQueue {
        private Stack<Integer> in;
        private Stack<Integer> out;

        /** Initialize your data structure here. */
        public MyQueue() {
            in = new Stack<>();
            out = new Stack<>();
        }

        /** Push element x to the back of queue. */
        public void push(int x) {
            in.push(x);
        }

        /** Removes the element from in front of queue and returns that element. */
        public int pop() {
            if(out.size() > 0)
            {
                return out.pop();
            }
            else
            {
                while(in.size()>0)
                {
                    out.push(in.pop());
                }

                return out.pop();
            }
        }

        /** Get the front element. */
        public int peek() {
            if(out.size() > 0)
            {
                return out.peek();
            }
            else
            {
                while(in.size()>0)
                {
                    out.push(in.pop());
                }

                return out.peek();
            }
        }

        /** Returns whether the queue is empty. */
        public boolean empty() {
            return (in.isEmpty() && out.isEmpty());
        }
    }
}
