package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/*
301. Remove Invalid Parentheses

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Example 1:

Input: "()())()"
Output: ["()()()", "(())()"]

Example 2:

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]

Example 3:

Input: ")("
Output: [""]

 */

/*
    DFS(Back Tracking)

   1.Set max removal boundaries: rmL, rmR, if not set, will return all possibilities
   2. Check if open parentheses == 0 to add result in HashSet(avoid duplicates)
   3. scan the string for dfs (no for loop since we don't need ordering)
   4. in dfs, we choose either use or remove　"(" or ")", add open when use "(", remove when use ")"

Complexity: O(2^n), every char has 2 choice: use or remove


 */
public class LC_0301_RemoveInvalidParentheses {
    public List<String> removeInvalidParentheses(String s) {
        int rmL = 0, rmR = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                rmL++;
            } else if (s.charAt(i) == ')') {
                if (rmL > 0) {
                    rmL--;
                } else {
                    rmR++;
                }
            }
        }
        Set<String> res = new HashSet<String>();
        dfs(s, 0, res, new StringBuilder(), rmL, rmR, 0);
        return new ArrayList<String>(res);
    }

    public void dfs(String s, int i, Set<String> res, StringBuilder sb, int rmL, int rmR, int open) {
        int len = sb.length();//decision point
        if (open < 0 || rmL < 0 || rmR < 0) return;//rmL rmR limit the max removal boundary,
        //else will return all possibilities["","()()","()","(())","()()()","(())()"]
        if (i == s.length()) {
            if (open == 0) res.add(sb.toString());//back tracking till the full length
            return;
        } else {
            //we don't need for loop since no ordering(not like subsets,permu problem)
            char c = s.charAt(i);
            if (c == '(') {//order matters here, once append c to sb, sb contains c when backtracking
                dfs(s, i + 1, res, sb, rmL - 1, rmR, open); //remove '('
                dfs(s, i + 1, res, sb.append('('), rmL, rmR, open + 1); //use '('
            } else if (c == ')') {
                dfs(s, i + 1, res, sb, rmL, rmR - 1, open); //remove ')'
                dfs(s, i + 1, res, sb.append(')'), rmL, rmR, open - 1); //use ')'
            } else {
                dfs(s, i + 1, res, sb.append(c), rmL, rmR, open);// append non '(',')' char
            }
        }
        sb.setLength(len);//reset back to decision point -- remove last char of sb
    }
}
