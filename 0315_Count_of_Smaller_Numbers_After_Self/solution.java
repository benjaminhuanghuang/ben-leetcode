package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
315. Count of Smaller Numbers After Self

You are given an integer array nums and you have to return a new counts array.
The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.


 */
public class LC_0315_CountofSmallerNumbersAfterSelf {
    /*
    https://www.youtube.com/watch?v=wjO48chdyBk

    time: O(n^2) Space: O(n);
     */
    public List<Integer> countSmaller(int[] nums) {
        Integer[] res = new Integer[nums.length];
        List<Integer> list = new ArrayList<>();

        for (int i = nums.length - 1; i >= 0; i--) {
            int index = findIndex(list, nums[i]);
            res[i] = index;
            list.add(index, nums[i]);

        }

        return Arrays.asList(res);
    }

    private int findIndex(List<Integer> list, int target) {
        if (list.size() == 0)
            return 0;

        int start = 0;
        int end = list.size() - 1;

        if (list.get(end) < target) return end + 1;
        if (list.get(start) >= target)
            return 0;

        while(start + 1< end)
        {
            int mid = (end-start) / 2 + start;
            if(list.get(mid) < target)
                start = mid + 1;
            else
                end = mid;
        }
        if(list.get(start) >= target)
            return start;
        return end;
    }
}
