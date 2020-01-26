package cn.huang.leetcode;

/*
396. Rotate Function

 Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

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
public class LC_0396_RotateFunction {
    public int maxRotateFunction(int[] A) {
        if (A.length == 0) {
            return 0;
        }
        int max = Integer.MIN_VALUE;
        for (int i = 0, k = 0; i < A.length; i++, k++) {
            int temp = 0;
            for (int j = 0; j < A.length; j++) {
                temp += j * A[(j - k + A.length) % A.length];
            }
            max = (max < temp) ? temp : max;
        }
        return max;
    }

    public int maxRotateFunction2(int[] A) {
        int sum = 0; // 计算出sum
        for (int i = 0; i < A.length; i++) {
            sum += A[i];
        }
        int base = 0; // 计算出F[0]的值
        for (int i = 0; i < A.length; i++) {
            base += i * A[i];
        }
        int max = base;
        for (int i = 1; i < A.length; i++) {
            int sumIndex = -i + A.length; // 公式展开后，得出如下
            base += sum - A.length * A[sumIndex];
            max = (max < base) ? base : max;
        }
        return max;
    }
}
