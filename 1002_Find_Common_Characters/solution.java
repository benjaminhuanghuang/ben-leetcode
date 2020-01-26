package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
1002. Find Common Characters

Given an array A of strings made only from lowercase letters, return a list of all characters that show up in
all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings
but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.



Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]



Note:

    1 <= A.length <= 100
    1 <= A[i].length <= 100
    A[i][j] is a lowercase letter


 */
public class LC_1002_FindCommonCharacters {
    public List<String> commonChars(String[] A) {
        int n = A.length;
        //每个字符串一个统计表, 记录每个字符串中 26个字符各出现几次
        int[][] cc = new int[n][26];

        for (int i = 0; i < n; i++) {
            for (char c : A[i].toCharArray()) {
                cc[i][c - 'a']++;
            }
        }

        List<String> result = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            int minCount = Integer.MAX_VALUE;    // 重要！每个字符在每个String中出现的最小次数
            for (int j = 0; j < n; j++) {
                minCount = Math.min(minCount, cc[j][i]);   // 有一个出现次数为0， minCount就会被清0
            }

            for (int j = 0; j < minCount; j++) {
                result.add(String.valueOf((char) (i + 'a')));
            }
        }

        return result;
    }
}
