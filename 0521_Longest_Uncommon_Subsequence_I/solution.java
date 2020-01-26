package cn.huang.leetcode;
/*
521. Longest Uncommon Subsequence I
 */
public class LC_0521_LongestUncommonSubsequence_I {
    //两串只要不想等，长的串的长度肯定是答案。
    public int findLUSlength(String a, String b) {
        if(a==null||b==null){
            return -1;
        }
        int lena = a.length();
        int lenb = b.length();

        if(a.equals(b)){
            return -1;
        }
        return lena>lenb?lena:lenb;
    }
}
