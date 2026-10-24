/*
227. Basic Calculator II

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . 
The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.
*/


public class Solution227 {
    public int Calculate(string s) {
        s = s.Trim();
        
        int num = 0;
        int left = 0;
        int right = 0;
        char op = '+';
        for(int i=0; i < s.Length; i++)
        {
            char c = s[i];

            if (c == ' ')
                continue;
            if (char.IsDigit(c))
            {
                num = num * 10 + c - '0';
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i== s.Length -1)
            {
                if ( op == '+')
                {
                    left = left + right;
                    right = num;
                }
                else if(op == '-')
                {
                    left = left + right;
                    right = -num;
                }
                else if(op == '*'){
                    right *= num;
                }
                else
                {
                    right = right / num;
                }
                num = 0;
                op = c;
            }
        }
        return left + right;     
    }
}