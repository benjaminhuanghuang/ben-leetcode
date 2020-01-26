package cn.huang.leetcode;

import java.util.Stack;

/*
739. Daily Temperatures
 Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days
 you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].

 */
public class LC_0739_DailyTemperatures {
    /*
    用递减栈Descending Stack来做，栈里只有递减元素的index
    1. 遍历数组，如果栈不空，且当前数字大于栈顶元素，那么如果直接入栈的话就不是递减栈了，
    所以我们取出栈顶元素，那么由于当前数字大于栈顶元素的数字，而且一定是第一个大于栈顶元素的数，那么我们直接求出下标差就是二者的距离了，
    然后继续看新的栈顶元素，直到当前数字小于等于栈顶元素停止，然后将数字入栈，这样就可以一直保持递减栈，且每个数字和第一个大于它的数的距离也可以算出来了，
     */
    public int[] dailyTemperatures(int[] T) {
        if(T == null)
            return null;

        int[] res = new int[T.length];

        Stack<Integer> s = new Stack<>();
        for(int i =0; i < T.length;i ++)
        {
            while(!s.isEmpty() && T[i] > T[s.peek()])
            {
                int t = s.pop();
                res[t] = i -t;
            }
            s.push(i);
        }

        return res;
    }
}
