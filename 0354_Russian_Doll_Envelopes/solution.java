package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

/*
354. Russian Doll Envelopes

You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into
another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.

Example:

Input: [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).


 */

/*

思路：一个Longest Increasing Subsequence 的变形，先对数组以width进行升序排序，如果width相等就以height降序排序．
因为这样可以保证依次遍历数组的时候后面的width始终比前面的大并且如果高度也大于前面的就一定可以包含前面的．
如果不对height降序排列形如[6,4], [6,7]前面是不能包含后面一个的．

 */
public class LC_0354_RussianDollEnvelopes {
    public int maxEnvelopes_Naive(int[][] envelopes) {
        if (envelopes == null || envelopes.length == 0)
            return 0;

        Arrays.sort(envelopes, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if (a[0] != b[0]) {
                    return a[0] - b[0];
                } else {
                    return a[1] - b[1];
                }
            }
        });
        int max = 1;
        int[] arr = new int[envelopes.length];
        for (int i = 0; i < envelopes.length; i++) {
            arr[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    arr[i] = Math.max(arr[i], arr[j] + 1);
                }
            }
            max = Math.max(max, arr[i]);
        }

        return max;
    }
    /*
        Binary Search
     */

    public int maxEnvelopes(int[][] envelopes) {
        if (envelopes == null || envelopes.length == 0)
            return 0;

        Arrays.sort(envelopes, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if (a[0] != b[0]) {
                    return a[0] - b[0]; //ascending order
                } else {
                    return b[1] - a[1]; // descending order
                }
            }
        });

        ArrayList<Integer> list = new ArrayList<Integer>();

        for (int i = 0; i < envelopes.length; i++) {

            if (list.size() == 0 || list.get(list.size() - 1) < envelopes[i][1])
                list.add(envelopes[i][1]);

            int l = 0;
            int r = list.size() - 1;

            while (l < r) {
                int m = l + (r - l) / 2;
                if (list.get(m) < envelopes[i][1]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }

            list.set(r, envelopes[i][1]);
        }

        return list.size();
    }

    public static int maxEnvelopes_dp(int[][] envelopes) {
        if (envelopes == null || envelopes.length == 0 || envelopes[0] == null || envelopes[0].length != 2)
            return 0;

        Arrays.sort(envelopes, new Comparator<int[]>() {
            public int compare(int[] arr1, int[] arr2) {
                if (arr1[0] == arr2[0])
                    return arr2[1] - arr1[1];
                else
                    return arr1[0] - arr2[0];
            }
        });

        int dp[] = new int[envelopes.length];
        int len = 0;
        for (int[] envelope : envelopes) {
            int index = Arrays.binarySearch(dp, 0, len, envelope[1]);
            if (index < 0) index = -(index + 1);
            dp[index] = envelope[1];
            if (index == len) len++;
        }
        return len;
    }

}
