package cn.huang.leetcode;
/*
673. Number of Longest Increasing Subsequence
 Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:

Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:

Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

 */
public class LC_0673_NumberofLongestIncreasingSubsequence {
    /*
    数组dp[x]表示以x结尾的子序列中最长子序列的长度

    数组dz[x]表示以x结尾的子序列中最长子序列的个数
     */
    public int findNumberOfLIS(int[] nums) {
        int numLength = nums.length;
        int result = 0;
        int maxLength = 0;
        int[] lengths =  new int[numLength];
        int[] numbers = new int[numLength];
        for(int i = 0; i<numLength; i++){
            lengths[i] = numbers[i] = 1;
            for(int j = 0; j <i ; j++){
                if(nums[i] > nums[j]){
                    if(lengths[i] == lengths[j] + 1)
                        numbers[i] += numbers[j];
                    if(lengths[i] < lengths[j] + 1){
                        lengths[i] = lengths[j] + 1;
                        numbers[i] = numbers[j];
                    }
                }
            }
            if(maxLength == lengths[i]){
                result += numbers[i];
            }
            if(maxLength < lengths[i]){
                maxLength = lengths[i];
                result = numbers[i];
            }
        }
        return result;
    }
}
