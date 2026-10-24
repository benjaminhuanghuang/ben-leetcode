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