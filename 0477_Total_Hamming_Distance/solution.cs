/*
477. Total Hamming Distance
The Hamming distance between two integers is the number of positions at which the corresponding 
bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.

 */

public class Solution477
{
    /*
    对于一个数组中，全部数字二进制的任意一位，汉明距离的总和为1的个数乘以0的个数。而数组中的数皆为int类型，所以一共需要进行32次循环。
     */
    public int TotalHammingDistance(int[] nums)
    {
        int sum = 0;
        for (int i = 0; i < 32; i++)
        {
            int ones = 0;
            for (int j = 0; j < nums.Length; j++)
                ones += (nums[j] >> i) & 0x1;
            sum += ones * (nums.Length - ones);
        }
        return sum;
    }
}