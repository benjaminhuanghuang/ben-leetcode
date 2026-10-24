/*
219. Contains Duplicate II

Given an array of integers and an integer k, find out whether there are two distinct indices i and j 
in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

*/
using System.Collections.Generic;

public class Solution219 {
    public bool ContainsNearbyDuplicate(int[] nums, int k) {
        var myDictionary = new Dictionary<int, int>();
        
        for(var i = 0; i < nums.Length; i++)
        {
            if(myDictionary.ContainsKey(nums[i]))
            {
                if(i - myDictionary[nums[i]] <= k)
                    return true;
                else
                    myDictionary[nums[i]] = i;
            }
            else
                myDictionary.Add(nums[i], i);
        }
        
        return false;
    }
}