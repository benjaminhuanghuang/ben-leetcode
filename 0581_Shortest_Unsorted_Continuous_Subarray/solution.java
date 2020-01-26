package cn.huang.leetcode;

import java.util.Arrays;
import java.util.Stack;

/*
    581. Shortest Unsorted Continuous Subarray

 */
public class LC_0581_ShortestUnsortedContinuousSubarray {
    /*
        monotone stack
        https://www.youtube.com/watch?v=8wHH9txAK34
        * keep a increasing monotonic stack (up slop), keep poping element when there is a down element
         until up slop again, then the current stack index is where the current element should be when sorted ascendent


        * time complexity: o(n^2), space complexity: o(n)
     */
    public int findUnsortedSubarray(int[] nums) {
        if (nums.length < 2) {
            return 0;
        }
        Stack<Integer> stack = new Stack<>();
        int leftBound = nums.length - 1, rightBound = 0;
        for (int i = 0; i < nums.length; i++) {
            if (stack.isEmpty() || nums[i] >= nums[stack.peek()]) {
                stack.push(i);
            } else {
                leftBound = Math.min(leftBound, stack.pop());
                i--;
            }
        }
        stack.clear();
        for (int i = nums.length - 1; i >= 0; i--) {
            if (stack.isEmpty() || nums[i] <= nums[stack.peek()]) {
                stack.push(i);
            } else {
                rightBound = Math.max(rightBound, stack.pop());
                i++;
            }
        }
        return rightBound - leftBound > 0 ? rightBound - leftBound + 1 : 0;
    }

    public int findUnsortedSubarray_Sort(int[] nums) {
        if (nums == null)
            return 0;

        int[] sorted = Arrays.copyOf(nums, nums.length);
        Arrays.sort(sorted);

        int start = -1;
        int end = -1;
        int length = 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != sorted[i]) {
                if (start == -1)
                    start = i;
                end = i;
            }
        }
        if (start == end)
            length = 0;
        else
            length = end - start + 1;

        return length;
    }
}
