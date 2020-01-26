package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
967. Numbers With Same Consecutive Differences

Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.



Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.

Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]



Note:

    1 <= N <= 9
    0 <= K <= 9


 */
public class LC_0967_NumbersWithSameConsecutiveDifferences {
    public int[] numsSameConsecDiff(int N, int K) {
        List<Integer> list = new ArrayList<>();
        if (N == 0)
            return new int[0];
        if (N == 1)
            list.add(0);      // edge case
        dfs(N, K, list, 0);

        return list.stream().mapToInt(i -> i).toArray();   //list.toArray(new int[list.size()]); doesn't work for primitives
    }

    public void dfs(int N, int K, List<Integer> list, int number) {
        if (N == 0) {   // base case, if you have added enough number of integers then append it to list; Here N is used as the total digits in temporary number
            list.add(number);
            return;
        }
        for (int i = 0; i < 10; ++i) {
            if (i == 0 && number == 0)    // Do not add 0 at begining of a number
                continue;
            else if (number == 0 && i != 0) {     // base case, we add all the digits when we do not have any previous digit to check if difference = K
                dfs(N - 1, K, list, i);
            } else {
                if (Math.abs((number % 10) - i) == K) {
                    dfs(N - 1, K, list, number * 10 + i);    // General dfs to add the digit at the units place and reducing the number of digits by 1.
                }
            }
        }
    }
}
