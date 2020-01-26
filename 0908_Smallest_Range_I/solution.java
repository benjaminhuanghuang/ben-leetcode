package cn.huang.leetcode;

public class LC_0908_SmallestRangeI {
    public int smallestRangeI(int[] A, int K) {
        if(A == null || A.length == 0)
        {
            return 0;
        }

        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;


        for(int i =0 ;i < A.length; i++)
        {
            if (A[i] < min)
                min = A[i];
            if (A[i]> max)
                max = A[i];
        }

        return Math.max(0, (max-min - 2*K));
    }
}
