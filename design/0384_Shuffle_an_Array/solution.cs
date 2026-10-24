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