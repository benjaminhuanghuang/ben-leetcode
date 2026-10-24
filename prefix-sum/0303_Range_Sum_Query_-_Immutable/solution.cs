using System.Collections.Generic;

public class NumArray {
    private int[] nums;
    private Dictionary<int, int> dict = new Dictionary<int, int>();
    public NumArray(int[] nums) {
        this.nums = nums;
        int sum = 0;
        for(int i =0; i< nums.Length;i++){
            sum += nums[i];
            this.dict[i] = sum;
        }
    }

    public int SumRange(int i, int j) {
        if (i == 0)
            return this.dict[j];
        return this.dict[j] - this.dict[i-1];
    }
}
