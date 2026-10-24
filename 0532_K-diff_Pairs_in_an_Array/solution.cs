using System;
using System.Collections.Generic;

public class Solution532 {
    public int FindPairs(int[] nums, int k) {
        int ans = 0;
        Array.Sort(nums);
        HashSet<int> numSet = new HashSet<int>();
        HashSet<int> sameSet = new HashSet<int>();
        
        if (k == 0){
            for (int i =0 ;i < nums.Length; i++)
            {
                // numSet.Contains(nums[i]  the number has same value with others
                // !sameSet.Contains(nums[i])  Find same number at first time 
                if (!sameSet.Contains(nums[i]) && numSet.Contains(nums[i]))
                {   
                    ans++;
                    sameSet.Add(nums[i]);    
                }
                numSet.Add(nums[i]);
            }
        }
        else
        {
            for (int i = 0; i < nums.Length; i++) {
                if (!numSet.Contains(nums[i]) && numSet.Contains(nums[i] - k)) 
                    ans++;
                numSet.Add(nums[i]);
            }
        }
        return ans;
    }
}