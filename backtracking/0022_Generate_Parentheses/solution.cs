
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
using System;
using System.Collections;
using System.Collections.Generic;

public class Solution022 {
    public IList<string> GenerateParenthesis(int n) {
        var res = new List<string>();
        if (n <=0 )
            return res;
        
        this.GenerateParenthesisHelper(n, n, "", res);
        return res;
    }

    private void GenerateParenthesisHelper(int left, int right, string item, IList<string> res)
    {
        if (left == 0 && right == 0)
        {
            res.Add(item);
            return;
        }

        if (left > 0)
        {
            GenerateParenthesisHelper(left - 1, right, item + "(", res);
        }

        if (right > left)
        {
            GenerateParenthesisHelper(left, right - 1, item + ")", res);
        }
    } 

    // Iteration method
    // https://miafish.wordpress.com/2014/12/23/get-all-combinations-of-balanced-parentheses/
    // https://discuss.leetcode.com/topic/3474/an-iterative-method
    // f(n) will be put an extra () pair to f(n-1). 
    // Let the "(" always at the first position, to produce a valid result, we can only put ")" 
    // in a way that there will be i pairs () inside the extra () and n - 1 - i pairs () outside 
    // the extra pair.
    //f(n) = (f(0))f(n-1) + (f(1))f(n-2) + … + (f(n-2))f(1) + (f(n-1))f(0)
    public IList<string> GenerateParenthesis2(int n)
    {
        // res[0] is [""]
        // res[1] is ["()"]
        // res[2] is ["()(),(())"]
        // based on res[2][0] get ["()()(),(())(),(()())"]
        //       on res[2][1] get ["()(())),()(())"]
        var res = new List<List<string>>{new List<string>{""}};

        // start from res[1]
        for (int i = 1; i <= n; i++)
        {
            res.Add(new List<string>());
            for (int j = 0; j < i; j++)
            {
                var left = res[j];
                var right = res[i - j - 1];

                foreach (var front in left)
                {
                    foreach (var back in right)
                    {
                        res[i].Add("(" + front + ")" + back);
                    }
                }
            }
        }

        return res[n];
    }
}