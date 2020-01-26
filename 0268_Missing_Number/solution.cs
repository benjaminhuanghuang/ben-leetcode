/*
268. Missing Number

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing 
from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant 
extra space complexity?
*/

using System.Linq;

public class Solution268 {
    public int MissingNumber(int[] nums) {
        int n = nums.Length;
        return n * (n +1) /2 - nums.Sum();
    }
}