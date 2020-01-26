package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
131. Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]


 */
public class LC_0131_PalindromePartitioning {
    /*
    https://www.youtube.com/watch?v=keeHIReXbog

    time O(2^n) Space O(n)
     */
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();

        if (s == null || s.length() == 0)
            return res;

        helper(res, new ArrayList<>(), s, 0);
        return res;
    }


    private void helper(List<List<String>> res, List<String> list, String s, int pos) {
        if (s.length() == pos) {
            res.add(new ArrayList<>(list));
            return;
        }
        for (int i = pos; i < s.length(); i++) {
            if (isPalindrome(s, pos, i)) {  //如果[i,j]中字符不构成回文，那么不进行下一次递归，直接进入下一次循环判断[i,j+1]
                list.add(s.substring(pos, i + 1));
                helper(res, list, s, i + 1);  //如果[i,j]中字符构成回文，那么进行下一次递归，判断j+1之后字符是否构成回文
                list.remove(list.size() - 1);
            }
        }
    }

    private boolean isPalindrome(String s, int start, int end) {  //判断s中[start,end]字符是否构成回文
        while (start < end) {
            if (s.charAt(start++) != s.charAt(end--))
                return false;
        }
        return true;

    }
}
