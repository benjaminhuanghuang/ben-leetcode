package cn.huang.leetcode;

/*

679. 24 Game
 You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.

Example 1:

Input: [4, 1, 8, 7]
Output: True
Explanation: (8-4) * (7-1) = 24

Example 2:

Input: [1, 2, 1, 2]
Output: False

Note:

    The division operator / represents real division, not integer division. For example, 4 / (1 - 2/3) = 12.
    Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
    You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.


 */
public class LC_0679_24Game {
    private static final double E = 0.0001;

    public boolean judgePoint24(int[] nums) {
        if (nums == null || nums.length != 4) {
            return false;
        }
        double[] dnums = new double[4];
        for (int i = 0; i < 4; i++) {
            dnums[i] = nums[i];
        }
        return generated24(dnums, 4);
    }

    private boolean generated24(double[] nums, int n) {
        if (n == 1) {
            return Math.abs(nums[0] - 24.0) < E;
        }
        for (int i = 0; i < n - 1; i++) {
            double origI = nums[i];
            for (int j = i + 1; j < n; j++) {
                double origJ = nums[j];
                nums[j] = nums[n - 1];
                for (double c : getCombinations(origI, origJ)) {
                    nums[i] = c;
                    if (generated24(nums, n - 1)) {
                        return true;
                    }

                }
                nums[j] = origJ;
            }
            nums[i] = origI;
        }
        return false;
    }

    private double[] getCombinations(double a, double b) {
        return new double[]{a + b, a - b, b - a, a / b, b / a, a * b};
    }
}
