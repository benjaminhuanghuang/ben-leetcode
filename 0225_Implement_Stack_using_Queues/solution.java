package cn.huang.leetcode;

import java.util.LinkedList;
import java.util.Queue;

/*
225. Implement Stack using Queues
 */
public class LC_0225_ImplementStackusingQueues {
    //https://blog.csdn.net/coder_orz/article/details/51605052
    //https://www.youtube.com/watch?v=grAYBHmn4Cs
    class MyStack {

        Queue<Integer> data = new LinkedList<Integer>();
        Queue<Integer> helper = new LinkedList<Integer>();


        // Push element x onto stack.
        public void push(int x) {
            data.offer(x);
        }

        // Removes the element on top of the stack.
        public int pop() {
            while(data.size() > 1)
            {
                helper.offer(data.poll());
            }
            int element = data.poll();
            // switch data and helper
            Queue<Integer> tmp = data;
            data = helper;
            helper = tmp;
            return element;
        }

        // Get the top element.
        public int top() {
            while(data.size() > 1)
            {
                helper.offer(data.poll());
            }
            int element = data.peek();
            // switch data and helper
            helper.offer(data.poll());
            Queue<Integer> tmp = data;
            data = helper;
            helper = tmp;
            return element;
        }

        // Return whether the stack is empty.
        public boolean empty() {
            return data.isEmpty();
        }
    }
}
