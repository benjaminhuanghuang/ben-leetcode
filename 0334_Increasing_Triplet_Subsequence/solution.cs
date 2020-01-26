/*
334. Increasing Triplet Subsequence

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/
using System;
public class Solution334 {
    public bool IncreasingTriplet(int[] nums) {
        int m1 = int.MaxValue, m2 = int.MaxValue;
        foreach (int n in nums) 
        {
            if (m1 >= n)  // smallest num 
                m1 = n;
            else if (m2 >= n) 
                m2 = n;   // second smallest num
            else          // current number is bigger than m1 and m2
                return true;
        }
        return false;
    }
}