package cn.huang.leetcode;

/*
303. Range Sum Query - Immutable

 */
public class LC_0303_RangeSumQuery_Immutable {
    /*
    sums[i] = nums[0] + nums[1] + … + nums[i]

    sumRange(i, j) = sums[j] – sums[i – 1]
     */
    class NumArray {
        private int[] rangeSum;

        public NumArray(int[] nums) {
            if (nums.length > 0) {
                rangeSum = new int[nums.length];
                rangeSum[0] = nums[0];
                for (int i = 1; i < nums.length; i++) {
                    rangeSum[i] = rangeSum[i - 1] + nums[i];
                }
            }
        }

        public int sumRange(int i, int j) {
            if (i == 0)
                return rangeSum[j];
            else
                return rangeSum[j] - rangeSum[i - 1];
        }
    }

}
