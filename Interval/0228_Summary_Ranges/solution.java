package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*

228. Summary Ranges

Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:

Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.

Example 2:

Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.


 */
public class LC_0228_SummaryRanges {
    // 两个指针 start, end.  如果nums[end+1] = nums[end]+1, 就移动end指针,
    // 否则, 插入字符串nums[start]->nums[end].
    public List<String> summaryRanges(int[] nums) {
        List<String> res = new ArrayList<>();
        if (nums == null || nums.length < 1)
            return res;

        int start = 0, end = 0;
        while (end < nums.length) {
            if (end + 1 < nums.length && nums[end + 1] == nums[end] + 1) {
                end++;
            } else {
                if (start == end) {
                    res.add(nums[start]+"");
                } else {
                    String str = nums[start] + "->" + nums[end];
                    res.add(str);
                }
                ++end;
                start = end;
            }
        }
        return res;
    }
}
