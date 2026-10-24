/*
10. Regular Expression Matching

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

*/
/*
https://www.youtube.com/watch?v=DqhPJ8MzDKM
https://www.youtube.com/watch?v=l3hda49XcDE
State: 
    dp[i][j] 表示从s中取i个字符,是否match从p中取j个字符, i取值0-s.Length, j取值0-s.Length

init
    dp[0][0] = true  从s和p中都取0个字符
    dp[n][0] = false 从s中取n个字符，p中取0个字符
    dp[0][1] = false 从s中取0个字符，p中取1个字符
    dp[0][2] 从s中取0个字符，p中取2个字符,如果p中的第二个字符是*, ""可以match"a*"
    根据数组初始值的特性无序init 初值为false的元素

转移方程

 */

public class Solution010 {
    
    // State: 
    // dp[i][j] : s[0:i-1] matches p[0:j-1]
    // https://miafish.wordpress.com/2015/01/24/leetcode-oj-c-regular-expression-matching/
    // if we know all previous i, j matches or not, can we judge i, j match or not. 
    // if p[j-1] != '.' and p[j-1] != '*'
    //      dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1])
    // if p[j-1] == '.':
    //      dp[i][j] = dp[i-1][j-1]
    // if p[j-1] == '*'
    //      match 0 chart,  dp[i][j] = dp[i][j-2]
    public bool IsMatch(string s, string pattern) 
    {
        var dp = new bool[s.Length + 1, pattern.Length + 1];
        dp[0, 0] = true;
        for (int i = 1; i < pattern.Length; i++)  
        {
            // i is index, state中相应元素为i+1长度
            if (pattern[i] == '*')   // 从s中取0个字符，从p中取n个字符 "" match "a*", "a*c*"
                dp[0, i + 1] = dp[0, i - 1];
        }

        for (int i = 0; i < s.Length; i++)
        {
            for (int j = 0; j < pattern.Length; j++)
            {
                if (s[i] == pattern[j] || pattern[j] == '.')
                {
                    // current s[i] match p[j] or p[j] == "."
                    // i , j are index, state中相应元素为 i+1, j+1 表示长度
                    dp[i + 1, j + 1] = dp[i, j];
                }
                else if(pattern[j] == '*')
                {
                    // if p[j] == '*', we can go back 2 character and judge character * matches nothing.
                    // dp[i + 1, j + 1] = dp[i + 1, j - 1] 
                    //     sample: s = abcd   p = abcde*
                    // or if p[j – 1] == s[i – 1], we can assume character * matches one character.
                    // dp[i + 1, j + 1] = dp[i, j + 1] if (s[i] == pattern[j - 1] || pattern[j - 1] == '.')
                    //     sample :  s = abcdd   p= abcd*     s的当前字符和p中*前的字符match, 此时看
                    //         s的当前字符之前的字符串是否和p match
                    dp[i + 1, j + 1] = dp[i + 1, j - 1] || 
                        (dp[i, j + 1] && (s[i] == pattern[j - 1] || pattern[j - 1] == '.'));
                }
            }
        }
        return dp[s.Length, pattern.Length];
    }
    // http://bangbingsyb.blogspot.com/2014/11/leetcode-regular-expression-matching.html
    // if p[j-1] != '.' and p[j-1] != '*'
    //      dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1])
    // if p[j-1] == '.':
    //      dp[i][j] = dp[i-1][j-1]
    // if p[j-1] == '*'
    //      match 0 chart,  dp[i][j] = dp[i][j-2]
    //      match 1 chart
    //      match n chart, dp[i][j] = dp[i-1][j] && (p[j-2]=='.' || s[i-2]==p[j-2])
    public bool IsMatch_1(string s, string p) 
    {
        var dp = new bool[s.Length + 1, p.Length + 1];
        dp[0, 0] = true;

        // For case "aab", "c*a*b" or "", "c*c*"
        for (int i = 1; i < p.Length + 1; i++)
        {
            if (p[i - 1] == '*' && i >= 2) 
            {
                dp[0, i] = dp[0, i-2];
            }
        }

        for (int i = 1; i < s.Length + 1; i++)
        {
            for (int j = 1; j < p.Length + 1; j++)
            {
                if (p[j-1] == '.')
                {
                    dp[i, j] = dp[i-1, j-1];
                }
                else if(p[j-1] == '*')
                {
                    dp[i, j] = dp[i, j - 1] || dp[i, j - 2] || 
                             (dp[i-1, j] && (s[i-1] == p[j - 2] || p[j - 2] == '.'));
                }
                else{
                    dp[i, j] = dp[i-1, j-1] && (s[i-1] == p[j-1]);
                }
            }
        }

        return dp[s.Length, p.Length];
    }

    // https://miafish.wordpress.com/2015/01/24/leetcode-oj-c-regular-expression-matching/
    public bool isMatch_2(string s, string p)
    {
        if (p == null && s == null)
        {
            return true;
        }
        if (p == null || s == null)
        {
            return false;
        }
        return this.isMatchRecursion(s, 0, p, 0);
    }

    public bool isMatchRecursion(string s, int indexOfs, string p, int indexofp)
    {
        if (indexOfs >= s.Length)
        {
            while (indexofp + 1 < p.Length && p[indexofp + 1].Equals('*'))                 
            {                     
                indexofp += 2;                 
            }             
        }             
        if (indexOfs >= s.Length && indexofp >= p.Length)
        {
            return true;
        }
        if (indexOfs >= s.Length || indexofp >= p.Length)
        {
            return false;
        }

        var next = indexofp + 1 >= p.Length ? ' ' : p[indexofp + 1];

        if (next.Equals('*'))
        {
            if (s[indexOfs].Equals(p[indexofp]) || p[indexofp].Equals('.'))
            {
                // a* matches more than 0 of a in s
                return this.isMatchRecursion(s, indexOfs + 1, p, indexofp) 
                    // a* matches 0 of a in s
                    || this.isMatchRecursion(s, indexOfs, p, indexofp + 2);
            }
            
            return this.isMatchRecursion(s, indexOfs, p, indexofp + 2);
        }

        if (s[indexOfs].Equals(p[indexofp]) || p[indexofp].Equals('.'))
        {
            return this.isMatchRecursion(s, indexOfs + 1, p, indexofp + 1);
        }

        return false;
    }
}