package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
    119. Pascal's Triangle II
    [
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
    ]
    Could you optimize your algorithm to use only O(k) extra space?
 */
public class LC_0119_PascalsTriangle_II {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> res = new ArrayList<>();
        if (rowIndex < 0) return res;

        for (int row = 0; row <= rowIndex; row++) {
            // Add 1 to the row
            res.add(0, 1);
            // Calculate the values
            for (int col = 1; col < res.size() - 1; col++) {
                res.set(col, res.get(col) + res.get(col + 1));
            }
        }
        return res;
    }
}
