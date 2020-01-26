/*
301. Remove Invalid Parentheses

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/
using System;
using System.Collections.Generic;

public class Solution301 {
    //http://bookshadow.com/weblog/2015/11/05/leetcode-remove-invalid-parentheses/
    // https://segmentfault.com/a/1190000005922178
    public IList<string> RemoveInvalidParentheses(string s) {
        var result = new List<string>();
        remove(s, result, 0, 0, new char[]{'(', ')'});
        return result;
    }

    private void remove(string s, List<string> result, int last_i, int last_j, char[] par) {
        for (int stack = 0, i = last_i; i < s.Length; i++) 
        {
            if (s[i] == par[0]) stack++;
            if (s[i] == par[1]) stack--;
            //如果'('比')'大或等的话，就继续扫下去
            if (stack >= 0) 
                continue;
            //否则，我们就找到当前有可能删去的')'，然后删掉看新的string
            for (int j = last_j; j <= i; j++) {
                if (s[j] == par[1] && (j == last_j || s[j - 1] != par[1])) 
                {
                    remove(s.Substring(0, j) + s.Substring(j + 1, s.Length - j - 1), result, i, j, par);
                }
            }
            return;
        }
        
        var tmp = s.ToCharArray();
        Array.Reverse(tmp);
        string reversed = new string(tmp);
        
        //如果只从左到右扫了，par[0]还是'('的时候，我们还要再从右往左扫一遍
        if (par[0] == '(') {
            remove(reversed, result, 0, 0, new char[]{')', '('});
        } else {
            //否则两遍都扫完了，就加入结果中去
            result.Add(reversed);
        }
    }
}

/*
    var s = new Solution301();
    var result = s.RemoveInvalidParentheses("()())()"); 

    Console.WriteLine(result);
*/