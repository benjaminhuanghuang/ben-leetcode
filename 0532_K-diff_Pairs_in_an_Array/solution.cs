/*
532. K-diff Pairs in an Array

Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. 
Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their 
absolute difference is k.

Example 1:
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.

Example 2:
Input:[1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

Example 3:
Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).

Note:
The pairs (i, j) and (j, i) count as the same pair.
The length of the array won't exceed 10,000.
All the integers in the given input belong to the range: [-1e7, 1e7].
 */
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