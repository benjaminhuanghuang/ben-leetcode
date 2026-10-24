package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
    118. Pascal's Triangle
 */
public class LC_0118_PascalsTriangle {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();

        for (int row = 0; row < numRows; row++) {
            List<Integer> nums = new ArrayList<>();
            for (int col = 0; col < row; col++) {
                if (col == 0 || col == row)
                    nums.add(1);
                else {
                    nums.add(res.get(row - 1).get(col - 1) + res.get(row - 1).get(col));
                }
            }
            res.add(nums);
        }
        return res;
    }
}
