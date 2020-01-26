/*
525. Contiguous Array

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

*/

/*  Solution 1 DP
http://bookshadow.com/weblog/2017/02/19/leetcode-contiguous-array/

 */


/*   Solution 2
0和1数组，可以考虑把0换成-1，变成-1和1数组，那么本质上就是找是否有下标从i～j的总和为0的子数组

令map保存sum和sum对应的indexd的值，遍历数组每次计算数组当前的sum，如果当前sum之前已经出现过，
比如说之前有过一个sum = 2，现在又sum = 2了，说明在第一次sum等于2的时候，它前面所有元素加起来总和是2，
那么在它前面去掉2个元素1就能满足0，同理当前的sum = 2也可以通过去掉最前面的2个元素1使sum = 0，
所以看看i – m[sum]是否比之前的最大值大，如果比之前最大值大就更新最大值～

*/

using System;
using System.Collections.Generic;
public class Solution525
{
    public int FindMaxLength_2(int[] nums)
    {
        int result = 0, sum = 0;
        for (int i = 0; i < nums.Length; i++)
            if (nums[i] == 0) 
                nums[i] = -1;
        Dictionary<int, int> sum_index = new Dictionary<int,int>();
        sum_index[0] = -1;
        for (int i = 0; i < nums.Length; i++) {
            sum += nums[i];
            if (sum_index.ContainsKey(sum))
                result = Math.Max(result, i - sum_index[sum]);
            else
                sum_index[sum] = i;
        }
        return result;
    }
}