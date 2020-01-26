/*
217. Contains Duplicate
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in 
the array, and it should return false if every element is distinct.

*/
using System.Linq;
using System.Collections.Generic;

public class Solution217 {
    public bool ContainsDuplicate(int[] nums) {
        HashSet<int> s = new HashSet<int>(nums);
        return nums.Length > s.Count; 
    }

    public bool ContainsDuplicate_2(int[] nums)
    {
        return nums.Length > nums.Distinct().Count();
    }
}