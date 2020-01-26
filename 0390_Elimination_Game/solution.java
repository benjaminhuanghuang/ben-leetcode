package cn.huang.leetcode;

/*
390. Elimination Game

 There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other
 number afterward until you reach the end of the list.

Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.

We keep repeating the steps again, alternating left to right and right to left, until a single number remains.

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
public class LC_0390_EliminationGame {
    public int lastRemaining(int n) {
        return help(n, true);
    }

    int help(int n, boolean left2right) {
        if (n == 1) return 1;
        if (left2right) {
            return 2 * help(n / 2, false);
        } else {
            return 2 * help(n / 2, true) - 1 + n % 2;
        }
    }
    /*
    http://www.cnblogs.com/grandyang/p/5860706.html
    第一次从左往右删除的时候，奇数都被删掉了，剩下的都是偶数。如果我们对所有数都除以2，那么得到一个1到n/2的新数列。
    下一次我们从右往左删出，那么返回的结果应该是调用递归的结果lastRemaining(n / 2)在数组1到n/2之间的镜像。
    何为镜像，比如1, 2, 3, 4这个数字，2的镜像就是3, 1的镜像是4，
     */
    int lastRemaining2(int n) {
        return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
    }
}
