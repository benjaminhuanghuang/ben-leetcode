package cn.huang.leetcode;
/*
467. Unique Substrings in Wraparound String

Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like
this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s.
In particular, your input is the string p and you need to output the number of different non-empty substrings of p in the string s.

Note: p consists of only lowercase English letters and the size of p might be over 10000.

Example 1:

Input: "a"
Output: 1

Explanation: Only the substring "a" of string "a" is in the string s.

Example 2:

Input: "cac"
Output: 2
Explanation: There are two substrings "a", "c" of string "cac" in the string s.

Example 3:

Input: "zab"
Output: 6
Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.

 */


/*
这道题是说给了一个字符串P，需要从其中找到所有出现在S中的子串。
这里的S的子串是一个比较神奇的存在，起就是abcdedf..zabcde…这样无限迭代下去的一个串，也就是只要P的字符串一直递增就好（z->a进位）

所以解题方法也很直接：
找出以’a-z’每个字符结尾的情况下，最长的子串有多长，然后将其相加就可以

其实就是找出P中有多少个子串，子串能够在abcdedf...zabcdefg...zab...这样的一个子串里面找到
 也就是递增的过程
   考虑为一个26进制的数的序列
   使用dp的方式，找到以某个字符结尾的最长的有多少种可能
 */
public class LC_0467_UniqueSubstringsinWraparoundString {
    public int findSubstringInWraproundString(String p) {
        int p_int[] = new int[p.length()];
        int count[] = new int[26];
        //记录每个位置的字符
        for (int i = 0; i < p.length(); i++) {
            p_int[i] = p.charAt(i) - 'a';
        }
        int res = 0;
        int maxLen = 0;
        for (int i = 0; i < p.length(); i++) {
            // 递增
            if (i > 0 && (p_int[i - 1] + 1) % 26 == p_int[i]) {
                maxLen++;
            } else {
                maxLen = 1;
            }
            count[p_int[i]] = Math.max(count[p_int[i]], maxLen);
        }
        for (int i = 0; i < 26; i++)
            res += count[i];
        return res;
    }

    public int findSubstringInWraproundString2(String p) {
        if (p.length() == 0)
            return 0;
        int[] length = new int[26];   // 记录以某个字符结尾的string的长度
        int count = 1;
        length[p.charAt(0) - 'a'] = 1;
        for (int i = 1; i < p.length(); i++) {
            if (p.charAt(i) - p.charAt(i - 1) == 1 || p.charAt(i) - p.charAt(i - 1) == -25)
                count++;
            else
                count = 1;
            length[p.charAt(i) - 'a'] = length[p.charAt(i) - 'a'] > count ? length[p.charAt(i) - 'a'] : count;
        }
        int res = 0;
        for (int num : length)
            res += num;
        return res;
    }
}
