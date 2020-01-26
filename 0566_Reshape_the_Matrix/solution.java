package cn.huang.leetcode;

/*
    566. Reshape the Matrix
    Input:
    nums =
    [[1,2],
     [3,4]]
    r = 1, c = 4
    Output:
    [[1,2,3,4]]
    Explanation:
    The row-traversing of nums is [1,2,3,4].
 */
public class LC_0566_ReshapetheMatrix {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        if (nums == null)
            return null;
        int rows = nums.length;
        int cols = nums[0].length;
        if (rows * cols != r * c) {
            return nums;
        }

        int[][] res = new int[r][c];

        for (int i = 0; i < r * c; i++) {
            res[i / c][i % c] = nums[i / cols][i % cols];
        }

        return res;
    }
}
