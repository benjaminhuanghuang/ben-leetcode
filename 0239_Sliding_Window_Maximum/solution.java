package cn.huang.leetcode;

import java.util.LinkedList;

/*
239. Sliding Window Maximum

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very
right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7]
Explanation:

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Note:
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

 */
public class LC_0239_SlidingWindowMaximum {
    /*
    https://www.programcreek.com/2014/05/leetcode-sliding-window-maximum-java/
    使用双向队列，时间复杂度O(n)。

    在队列中维持一个k长度窗口内的递减元素下标，为什么呢？因为当元素递增时，前面的元素就不需要了，因为最大值肯定不会是它们了。

    顺序扫描每一个元素，当队头的元素超出窗口视野的时候，将对头元素出队；然后检查队尾，如果队尾元素小于或等于当前元素，则队尾元素出队，重复检查队尾直至队列为空或者队尾元素大于当前元素。然后当前元素入队。

     */
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0)
            return new int[0];

        int[] result = new int[nums.length - k + 1];

        LinkedList<Integer> deque = new LinkedList<Integer>();

        for (int i = 0; i < nums.length; i++) {
            if (!deque.isEmpty() && deque.peekFirst() == i - k)
                deque.poll();

            while (!deque.isEmpty() && nums[deque.peekLast()] < nums[i]) {
                deque.removeLast();
            }

            deque.offer(i);

            if (i + 1 >= k)
                result[i + 1 - k] = nums[deque.peek()];
        }

        return result;
    }
    /*
    https://www.youtube.com/watch?v=2SXqBsTR6a8
    Monotonic queue
     */

}
