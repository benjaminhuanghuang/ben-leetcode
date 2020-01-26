/*
396. Rotate Function

Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, 
we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.

Example:

A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.

*/
using System;
public class Solution396 {
    //http://bookshadow.com/weblog/2016/09/11/leetcode-rotate-function/
    //用每一行系数与其上一行做差，差值恰好为sum(A) - size * A[size - x]，其中x为行数
    public int MaxRotateFunction(int[] A) {
        int n = A.Length;
        //假设不旋转下的f0的值
        int f0 = 0;
        //当顺序位移一位后，抛出变成0的那个，那么整体增加的
        int sumOfA = 0;
        for(int i=0; i<n; i++){
            f0 += A[i] * i;
            sumOfA += A[i];
        }
        int max = f0;
        int fi = f0;
        //开始考虑旋转的
        for(int i=1; i<n; i++){
            //旋转后，所有加1
            fi += sumOfA;
            //上一回合的 最后一个需要减去n个(原来n-1 刚刚又加了一个)
            fi -= n * A[ n -i ];
            max = Math.Max(max,fi);
        }
        return max;
    }
}