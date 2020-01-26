/*
239. Sliding Window Maximum

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

Hint:
    How about using a data structure such as deque (double-ended queue)?
    The queue size need not be the same as the window’s size.
    Remove redundant elements and the queue should store only elements that need to be considered.
*/

using System.Collections.Generic;

public class Solution239 {
    public int[] MaxSlidingWindow(int[] nums, int k) {
        List<int> ans = new List<int>();
        List<int> deque = new List<int>();
        if (nums.Length == 0) 
            return ans.ToArray();
    
        for (int i = 0; i < k - 1; i++) {
            inQueue(deque, nums[i]);
        }
        
        for(int i = k - 1; i < nums.Length; i++) {
            inQueue(deque, nums[i]);
            ans.Add(deque[0]);
            outQueue(deque, nums[i - k + 1]);
        }
        return ans.ToArray();
    }

    void inQueue(List<int> deque, int num) {
        while (deque.Count > 0 && deque[deque.Count -1] < num) {
            deque.RemoveAt(deque.Count - 1);
        }
        deque.Add(num);
    }
    
    void outQueue(List<int>  deque, int num) {
        if (deque[0] == num) {
            deque.RemoveAt(0);
        }
    }
}