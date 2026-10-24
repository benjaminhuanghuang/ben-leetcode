/*
10. Regular Expression Matching

https://leetcode.com/problems/regular-expression-matching/
*/

#include <string>

using namespace std;

/*
    https://www.youtube.com/watch?v=KN22ZEpRTFY&ab_channel=%E5%82%85%E7%A0%81%E7%88%B7
*/
bool isMatch(string s, string p)
{
    int m = s.length(), n = p.length();
    bool dp[m + 1][n + 1];
    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= n; ++j)
        {
            dp[i][j] = false;
        }

    dp[0][0] = true; // empty str matchs

    // dp[x][0] are false, empty p can not match any non-empty s
    for (int i = 1; i <= m; ++i)
        dp[i][0] = false;

    // go through the characters in p
    // s ""  matchs p "x*"
    for (int i = 1; i <= n; ++i)
    {
        // * only can folow a char, that means when [i - 1] == '*', i >= 2
        dp[0][i] = (p[i - 1] == '*' && dp[0][i - 2]);
    }

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            // the charcter in p can normal char, '.' or '*'
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') // '.' can match any char
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                // *前的字符 match s  s: "a", p:"a*" or ".*"
                if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
                {
                    // s: "a", p: "a*" or ".*" , * 表示3种情况 
                    // "a*" 表示空串，match由 dp[i][j - 2] 决定
                    // "a*" 表示"a"，match由 dp[i][j - 1] 决定
                    // "a*" 表示"aaaaaaaa"，match由 s中a之前的字符串s[0..i-1]  决定 也就是 dp[i-1][j]
                    dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j];
                }
                else
                {
                    //*前的字符'b' 不match 'a'，s: "a", p:"b*". 此时，只能把b*看成空串， match由b前面的字符决定
                    dp[i][j] = dp[i][j - 2];
                }
            }
        }
    return dp[m][n];
}

/*
    https://www.youtube.com/watch?v=l3hda49XcDE&t=460s&ab_channel=TusharRoy-CodingMadeSimple
*/

/*
DP
dp[i][j]表示 s[0..i-1] 是否匹配p[0..j-1].    i, j are length

if p[j - 1] != '*'

     dp[i][j] = dp[i-1][j-1]&& (p[j-1]=='.'||s[i-1]==p[j-1])

if p[j - 1] == '*', 设 p[j - 2] 为 x

      1) "x*" 重复0次：f[i][j] = dp[i][j - 2]

      2)"x*" 重复1次以上：f[i][j] = dp[i-1][j] && (p[j-2]=='.'||s[i-1]==p[j-2])


*/
bool isMatch(string s, string p)
{
    int m = s.length(), n = p.length();
    bool dp[m + 1][n + 1];
    dp[0][0] = 1; // empty str matchs

    // dp[x][0] are false, empty p can not match any non-empty s
    for (int i = 1; i <= m; ++i)
        dp[i][0] = 0;

    // go through the characters in p
    // s ""  matchs p "x*"
    for (int i = 1; i <= n; ++i)
    {
        dp[0][i] = p[i - 1] == '*' && dp[0][i - 2];
    }

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (p[j - 1] != '*')
                dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == '.' || s[i - 1] == p[j - 1]);
            else
                dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (p[j - 2] == '.' || s[i - 1] == p[j - 2]));
        }
    return dp[m][n];
}

/*
https://zxi.mytechroad.com/blog/searching/leetcode-10-regular-expression-matching/

Time complexity: O((|s| + |p|) * 2 ^ (|s| + |p|))
Space complexity: O(|s| + |p|)
*/
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        return isMatch(s.c_str(), p.c_str());
    }

private:
    bool isMatch(const char *s, const char *p)
    {
        if (*p == '\0')
            return *s == '\0';

        // normal case, e.g. 'a.b','aaa', 'a'
        if (p[1] != '*' || p[1] == '\0')
        {
            // no char to match
            if (*s == '\0')
                return false;

            if (*s == *p || *p == '.')
                return isMatch(s + 1, p + 1);
            else
                return false;
        }
        else
        {
            int i = -1;
            while (i == -1 || s[i] == p[0] || p[0] == '.')
            {
                if (isMatch(s + i + 1, p + 2))
                    return true;
                if (s[++i] == '\0')
                    break;
            }
            return false;
        }

        return false;
    }
};