/*
172. Factorial Trailing Zeroes [Easy]

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

*/

public class Solution172 {
    // n! = 1*2*3*4... *n
    // The number of trailing 0 = the count of 2*5 pair
    // https://discuss.leetcode.com/topic/6848/my-explanation-of-the-log-n-solution
    public int TrailingZeroes(int n) {
        int count_five = 0;
        while (n > 0)
        {
            int k = n / 5;
            count_five += k;
            n = k;
        }
        return count_five;
    }
}