package cn.huang.leetcode;

/*
453. Minimum Moves to Equal Array Elements

 */
public class LC_0453_MinimumMovestoEqualArrayElements {
    /*
    每次需要给除了数组最大值的所有数字加1

    全部n-1个值加1就是一个值减1
     */
    public int minMoves(int[] nums) {
        int sum = 0, len = nums.length;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            if (nums[i] < min)
                min = nums[i];
        }
        return sum - len * min;

    }
}
