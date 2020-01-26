/*
442. Find All Duplicates in an Array [Pocket Games]

Given an array of integers, 1 <= a[i] <= n (n = size of array), some elements appear twice and others 
appear once. 
Find all the elements that appear twice in this array. 

Could you do it "without extra space" and in O(n) runtime?

Example:
Input

[4,3,2,7,8,2,3,1]

Output

[2,3]
*/

using System;
using System.Collections.Generic;
     
public class Solution442 {
    public IList<int> FindDuplicates(int[] nums) {
        // when find a number i, flip the number at position i-1 to negative. 
        // if the number at position i-1 is already negative, i is the number that occurs twice.
        List<int> res = new List<int>();
        int len = nums.Length;

        for(int i=0; i < len; i ++)
        {
            int index = Math.Abs(nums[i]) - 1;
            if (nums[index]  <0 )
                res.Add(index + 1);
            nums[index] = - nums[index];
        }
        return res;
    }
}