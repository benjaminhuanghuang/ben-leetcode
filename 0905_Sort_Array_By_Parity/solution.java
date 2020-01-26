package cn.huang.leetcode;

public class LC_0905_SortArrayByParity {
    public int[] sortArrayByParity(int[] A) {
        if (A == null || A.length < 2)
            return A;
        int index_odd = A.length - 1;
        int index_even = 0;

        while (index_even < index_odd) {
            if (A[index_even] % 2 == 0) {
                index_even++;
            } else {
                int tmp = A[index_even];
                A[index_even] = A[index_odd];
                A[index_odd] = tmp;
                index_odd--;
            }
        }
        return A;
    }
}
