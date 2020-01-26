package cn.huang.leetcode;

/*
342. Power of Four
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?
 */
public class LC_0342_PowerofFour {
    public boolean isPowerOfFour(int num) {
        while (num > 0 && (num % 4 == 0)) {
            num /= 4;
        }
        return num == 1;
    }

    /*
        4的次方数就是将1向左移动两个位

        观察一下位置，4的次方中的1只出现在奇数的位置上！就是说，上面的二进制从右往左，第1，3，5，……位置上。

        So，如果我们与上一个可以在奇数上面选择位置的数，也就是 0101 0101 ……那么就把不是4次方的排除掉啦

        0101 0101 …… 十六进制表示为： 0x55555555

     */
    public boolean isPowerOfFour_Better(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num & 0x55555555) != 0;
    }
}
