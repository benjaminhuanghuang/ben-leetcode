package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
989. Add to Array-Form of Integer
For a non-negative integer X, the array-form of X is an array of its digits in left to right order.
For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.



Example 1:

Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: A = [2,1,5], K = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
Example 4:

Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
Output: [1,0,0,0,0,0,0,0,0,0,0]
Explanation: 9999999999 + 1 = 10000000000


Note：

1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
If A.length > 1, then A[0] != 0
 */
public class LC_0989_AddtoArray_FormofInteger {
    public List<Integer> addToArrayForm(int[] A, int K) {
        List<Integer> res = new ArrayList<>();
        int carry = 0;
        for (int i = A.length - 1; i >= 0; i--) {
            if (K > 0) {
                int digit = K % 10;

                res.add(0, (carry + A[i] + digit) % 10);
                carry = (carry + A[i] + digit) / 10;

                K = K / 10;
            } else {
                res.add(0, (carry + A[i]) % 10);
                carry = (carry + A[i]) / 10;
            }

        }
        while(K > 0)
        {
            int digit = K % 10;

            res.add(0, (carry + digit) % 10);
            carry = (carry + digit) / 10;

            K = K / 10;
        }
        if (carry > 0)
            res.add(0, carry);

        return res;
    }
}
