using System.Collections.Generic;

public class Solution387 {
    public int FirstUniqChar(string s) {
        var charDic = new Dictionary<char, int>();
        foreach(char c in s)
        {
            if (charDic.ContainsKey(c))
            {
                charDic[c]++;
            }
            else
            {
                charDic.Add(c, 1);
            }
        }
        for(int i =0; i< s.Length; i++)
        {
            if (charDic[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
}