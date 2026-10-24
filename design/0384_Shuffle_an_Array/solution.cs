/*
384. Shuffle an Array

Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/
using System;

public class Solution384 {
    private int[] nums;
    private int[] backup;
    public Solution384(int[] nums)
    {
        this.nums = nums;
        this.backup = nums;
    }
    public int[] Reset()
    {
        Array.Copy(this.nums, this.backup, this.nums.Length );
        return this.nums; 
    }

    public int[] Shuffle()
    {
        Random rand = new Random();
        for(int i =0; i<this.nums.Length ; i++)
        {
            int j = rand.Next(0, i+1);
            int tmp = this.nums[j];
            this.nums[j] = this.nums[i];
            this.nums[i] = tmp;
        }
        return this.nums;
    } 
}