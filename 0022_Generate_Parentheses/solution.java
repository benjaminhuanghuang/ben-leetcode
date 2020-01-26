package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
22. Generate Parentheses

 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

 */
public class LC_0022_GenerateParentheses {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        if (n <=0 )
            return res;

        this.GenerateParenthesisHelper(n, n, "", res);
        return res;
    }

    private void GenerateParenthesisHelper(int left, int right, String combination, List<String> res)
    {
        if (left == 0 && right == 0)
        {
            res.add(combination);
            return;
        }

        if (left > 0)
        {
            GenerateParenthesisHelper(left - 1, right, combination + "(", res);
        }

        if (right > left)
        {
            GenerateParenthesisHelper(left, right - 1, combination + ")", res);
        }
    }
}
