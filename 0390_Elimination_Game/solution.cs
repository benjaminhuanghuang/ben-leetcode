/*
390. Elimination Game

There is a list of sorted integers from 1 to n. Starting from left to right, remove the first 
number and every other number afterward until you reach the end of the list.

Repeat the previous step again, but this time from right to left, remove the right most number 
and every other number from the remaining numbers.

We keep repeating the steps again, alternating left to right and right to left, until a single 
number remains.

Find the last number that remains starting with a list of length n.

Example:

Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6
*/

public class Solution390 {
    // http://www.cnblogs.com/grandyang/p/5860706.html
    public int LastRemaining(int n) {
        return help(n, true);   
    }

    int help(int n, bool left2right) 
    {
        if (n == 1) return 1;
        // 如果n大于1，且是从左往右的话，我们返回2倍的对n/2的从右往左的遍历；
        // 如果是从右往左的话，稍稍麻烦一些，我们肯定还是要对n/2调用递归函数的，
        // 但是要分奇偶情况，如果n为奇数，返回2倍的对n/2的从左往右的遍历的值；
        //如果n为偶数，2倍的对n/2的从左往右的遍历的值，再减去1。
        if (left2right) 
        {
            return 2 * help(n / 2, false);
        } else 
        {
            return 2 * help(n / 2, true) - 1 + n % 2;
        }
    }
}