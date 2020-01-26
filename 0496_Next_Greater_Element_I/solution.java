package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
    496. Next Greater Element I

You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2.
Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2.
If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
 */
public class LC_0496_NextGreaterElement_I {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        /*
        思路是遍历nums1，对每一个数，找到它在nums2的位置，然后从这个位置开始向后遍历，
        如果能找到比它大的，就记下第一个比它大的数，否则记为-1
        */
        int len1 = nums1.length;
        int len2 = nums2.length;
        int[] result = new int[len1];

        for(int i = 0; i < len1; i++){
            result[i] = -1;
            int curNum = nums1[i];
            boolean startFlag = false;

            for(int j = 0; j < len2; j++){
                if(nums2[j] == curNum){
                    startFlag = true;
                    continue;
                }
                if(startFlag && nums2[j] > curNum){
                    result[i] = nums2[j];
                    break;
                }
            }
        }
        return result;

    }

    /*
        Monotone Stack
     */

}
