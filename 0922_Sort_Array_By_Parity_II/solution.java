package cn.huang.leetcode;

/*
Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

*/


public class LC_0922_SoreArrayByParityII {
    /*
        Use extra array
     */
    public int[] sortArrayByParityII_v1(int[] A) {
        if (A == null || A.length < 2) return A;

        int[] odd = new int[A.length / 2];
        int[] even = new int[A.length / 2];
        int[] result = new int[A.length];
        int evenIndex = 0;
        int oddIndex = 0;
        for (int i = 0; i < A.length; i++) {
            if (A[i] % 2 == 0) {
                even[evenIndex++] = A[i];
            } else {
                odd[oddIndex++] = A[i];
            }
        }

        for (int i = 0; i < A.length / 2; i++) {
            result[2 * i] = even[i];
            result[2 * i + 1] = odd[i];
        }
        return result;
    }

    public int[] sortArrayByParityII_v2(int[] A) {
        if (A == null || A.length < 2) return A;

        int evenLeft = 0;
        int oddLeft = 1;
        int oddRight = A.length - 1;
        int evenRight = A.length - 2;

        while (evenLeft < evenRight && oddLeft < oddRight) {
            if (A[evenLeft] % 2 == 0) {
                evenLeft += 2;
            } else {
                int tmp = A[oddRight];
                A[oddRight] = A[evenLeft];
                A[evenLeft] = tmp;
                oddRight -= 2;
            }

            if (A[oddLeft] % 2 != 0) {
                oddLeft += 2;
            } else {
                int tmp = A[evenRight];
                A[evenRight] = A[oddLeft];
                A[oddLeft] = tmp;
                evenRight -= 2;
            }
        }
        return A;
    }
}
