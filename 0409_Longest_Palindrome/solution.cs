using System.Collections.Generic;

public class Solution409 {
    //用hashtable记录每个字符出现的次数，出现偶数次的字符和一个出现奇数次的字符可以构成Palindrome
    public int LongestPalindrome(string s) {
        Dictionary<char, int> dict = new Dictionary<char, int>();

        for (int i =0 ; i< s.Length; i++)
        {
            if (dict.ContainsKey(s[i]))
            {
                dict[s[i]]++;
            }
            else
            {
                dict.Add(s[i], 1);
            }
        }
        int res = 0;
        bool hasSingle = false;
        foreach (var pair in dict)
        {
            if (pair.Value % 2 == 1){
                hasSingle = true;
            }
            res += pair.Value /2;
        }
        res = res * 2;
        if (hasSingle)
            res ++;
        return res;
    }
}