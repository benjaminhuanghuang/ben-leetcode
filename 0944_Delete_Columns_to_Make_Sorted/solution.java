package cn.huang.leetcode;

import java.util.Arrays;

/*
    944. Delete Columns to Make Sorted
    We are given an array A of N lowercase letter strings, all of the same length.

    Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.

    For example, if we have a string "abcdef" and deletion indices {0, 2, 3}, then the final string after deletion is "bef".

    Suppose we chose a set of deletion indices D such that after deletions, each remaining column in A is in sorted order.

    Formally, the c-th column is [A[0][c], A[1][c], ..., A[A.length-1][c]]

Return the minimum possible value of D.length.
 */
public class LC_0944_DeleteColumnstoMakeSorted {
    public int minDeletionSize(String[] A) {
        int size = 0;
        int strLen = A[0].length();
        for(int i =0; i < strLen;i ++)
        {
            char[] chars = new char[A.length];
            for(int j =0 ; j < A.length; j++)
            {
                chars[j] = A[j].charAt(i);
            }
            String s1 = String.valueOf(chars);
            Arrays.sort(chars);
            String s2 = String.valueOf(chars);
            if(!s1.equals(s2))
                size++;
        }

        return size;
    }

    /*
    https://zxi.mytechroad.com/blog/simulation/leetcode-944-delete-columns-to-make-sorted/
     */
    public int minDeletionSize2(String[] A) {
        int ans = 0;
        for (int c = 0; c < A[0].length(); ++c)
            for (int r = 1; r < A.length; ++r) {
                if (A[r].charAt(c) < A[r - 1].charAt(c)) {
                    ++ans;
                    break;
                }
            }
        return ans;
    }
}
