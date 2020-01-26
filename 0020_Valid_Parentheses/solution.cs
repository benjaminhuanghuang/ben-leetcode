/*
20. Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
using System.Collections;
using System.Collections.Generic;
using  System.Linq;

public class Solution020 {
    public bool IsValid(string s) {
        Stack<char> stack = new Stack<char>();

        for (int i =0 ; i < s.Length; i++)
        {
            char c = s[i];
            if (c=='(' || c=='{' || c=='[')
            {
                stack.Push(c);
            }
            else  // ), } , ]
            {
                if (stack.Count == 0)
                    return false;
                char last = stack.Pop();
                if (c == ')' && last != '(')
                    return false;
                if (c == ']' && last != '[')
                    return false;
                if (c == '}' && last != '{')
                    return false;
            }
        }
        return !stack.Any<char>();
    }
}