package cn.huang.leetcode;

import java.util.LinkedList;
import java.util.List;

/*
    784	 Letter Case Permutation
    Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.
    Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]

 */
public class LC_0784_LetterCasePermutation {

    /*
        Time complexity O(n* 2^l)   l is the number of letters
        Space complexity O(n) + O(n* 2^l)    stack + solution

        Upper case A - Z, 65 - 90
        Lower case a - z, 97 - 122
        a - A = 32

        a = A ^ (1<<5)
        A = a ^ (1<<5)
     */
    public List<String> letterCasePermutation(String S) {
        List<String> result = new LinkedList<>();
        char[] charArray = S.toCharArray();
        dfs(charArray, 0, result);

        return result;
    }

    private void dfs(char[] charArray, int i, List<String> result) {
        if (i == charArray.length) {
            result.add(String.valueOf(charArray));
            return;
        }
        dfs(charArray, i + 1, result);
        if (!Character.isAlphabetic(charArray[i]))
            return;
        charArray[i] ^= (1 << 5);
        dfs(charArray, i + 1, result);
        charArray[i] ^= (1 << 5);
    }
}
