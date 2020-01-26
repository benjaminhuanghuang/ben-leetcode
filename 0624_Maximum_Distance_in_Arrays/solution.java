package cn.huang.leetcode;

import java.util.List;

/*
	624 Maximum Distance in Arrays
	Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different
	arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to
	be their absolute difference |a-b|. Your task is to find the maximum distance.

    Example 1:

    Input:
    [[1,2,3],
     [4,5],
     [1,2,3]]
    Output: 4
    Explanation:
    One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.


    Note:

    Each given array will have at least 1 number. There will be at least two non-empty arrays.
    The total number of the integers in all the m arrays will be in the range of [2, 10000].
    The integers in the m arrays will be in the range of [-10000, 10000].

 */
public class LC_0624_MaximumDistanceinArrays {
    /*
    既然数组都是有序的，那么差的绝对值最大的两个数字肯定是分别位于数组的首和尾，
    注意题目中说要从不同的数组中取数，那么即使某个数组的首尾差距很大，也不行。
     */
    public int maxDistance(List<List<Integer>> arrays) {
        int res = 0;
        int min = arrays.get(0).get(0);
        int max = arrays.get(0).get(arrays.get(0).size() - 1);

        for (int i = 1; i < arrays.size(); i++) {
            List<Integer> array = arrays.get(i);


            // Max of res, distance（min, last num）, distance(max, first num)
            res = Math.max(Math.abs(min - array.get(array.size() - 1)),
                           Math.max(Math.abs(array.get(0) - max), res));

            min = Math.min(min, array.get(0));
            max = Math.max(max, array.get(array.size() - 1));
        }
        return res;
    }
}
