package cn.huang.leetcode;
/*
503. Next Greater Element II    [Google]

 Given a circular array (the next element of the last element is the first element of the array), print the Next
 Greater Number for every element. The Next Greater Number of a number x is the first greater number to its
 traversing-order next in the array, which means you could search circularly to find its next greater number.

 If it doesn't exist, output -1 for this number.

Example 1:

Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number;
The second 1's next greater number needs to search circularly, which is also 2.

Note: The length of given array won't exceed 10000.
 */

import java.util.Stack;

/*
考点：Array 数组，Monotone Stack 单调栈
https://www.youtube.com/watch?v=5IAq5jd8O7Y
 */
public class LC_0503_NextGreaterElement_II {

    /*
     Time O(n^2)
     */
    public int[] nextGreaterElements_Naive(int[] nums) {
        int[] res = new int[nums.length];


        return res;
    }

    /*
    Monotone Stack 单调栈
    Time O(n) Space(n)
     */
    public int[] nextGreaterElements(int[] nums) {
        int[] res = new int[nums.length];
        Stack<Integer> stack = new Stack<>();

        for (int i = 2 * nums.length - 1; i >= 0; i--) {
            while (!stack.isEmpty() && nums[stack.peek()] <= nums[i % nums.length]) {
                // 直到当前元素比stack 顶部元素小或stack is empty
                stack.pop();
            }

            res[i % nums.length] = stack.empty() ? -1 : nums[stack.peek()];
            stack.push(i % nums.length);
        }

        return res;
    }
}
