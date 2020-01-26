package cn.huang.leetcode;

/*
    268. Missing Number
 */
public class LC_0268_MissingNumber {
    public int missingNumber(int[] nums) {
        if (nums == null)
            return 0;

        int n = nums.length;
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        return n * (n + 1) / 2 - sum;
    }
}
