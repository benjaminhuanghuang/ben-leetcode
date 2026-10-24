package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.

 */


/*
    https://www.youtube.com/watch?v=uMmFXWs_ZMY
*/
public class LC_0017_LetterCombinationsofaPhoneNumber {

    /*
        According the recursion tree, Time Complexity is O(branch factor ^ depth) = O(4^n)
        Space Complexity : sb is O(n), call stack is O(n)
     */
    public List<String> letterCombinations(String digits) {
        HashMap<Character, String> dict = new HashMap<Character, String>();
        dict.put('2', "abc");
        dict.put('3', "def");
        dict.put('4', "ghi");
        dict.put('5', "jkl");
        dict.put('6', "mno");
        dict.put('7', "pqrs");
        dict.put('8', "tuv");
        dict.put('9', "wxyz");
        dict.put('0', "");

        ArrayList<String> result = new ArrayList<String>();

        if (digits == null || digits.length() == 0)
            return result;

        dfs(digits, dict, 0, new StringBuilder(), result);

        return result;
    }

    private void dfs(String digits, Map<Character, String> dict, int index, StringBuilder combination, List<String> result) {
        if (index == digits.length()) {
            result.add(combination.toString());
            return;
        }
        char ch = digits.charAt(index);
        String values = dict.get(ch);

        for (Character c : values.toCharArray()) {
            combination.append(c);
            dfs(digits, dict, index + 1, combination, result);
            combination.deleteCharAt(combination.length() - 1);
        }
    }
}
