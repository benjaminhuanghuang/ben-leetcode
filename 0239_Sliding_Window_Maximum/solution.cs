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