using System.Collections.Generic;

public class Solution438 {
    //http://bookshadow.com/weblog/2016/10/23/leetcode-find-all-anagrams-in-a-string/
    public IList<int> FindAnagrams(string s, string p) {
        int ls = s.Length;
        int lp = p.Length;
        int count = lp;
        //字典cp记录要凑成目标字符串p的anagram，各字符分别缺多少个
        //整数count记录凑成目标字符串p一共还缺多少个字符
        var cp = new Dictionary<char, int>();
        foreach (char c in p)
        {
            if(!cp.ContainsKey(c))
                cp.Add(c, 1);
            else
                cp[c]++;
        }
      
        List<int> ans = new List<int>();

        for(int i =0 ; i<ls; i++)
        {
            if(cp.ContainsKey(s[i]))
            {
                if (cp[s[i]] >=1)
                    count -= 1;

                cp[s[i]] -= 1;
                if (i >= lp){
                    if(cp.ContainsKey(s[i - lp]))
                    {
                        if (cp[s[i - lp]] >= 0)
                            count += 1;
                        cp[s[i - lp]] += 1;
                    }
                }

                if (count == 0)
                    ans.Add(i - lp + 1);
            }
        }
        return ans;
    }

    public IList<int> FindAnagrams_2(string s, string p) {
        int ls = s.Length;
        int lp = p.Length;
        var cp = new Dictionary<char, int>();
        var cs = new Dictionary<char, int>();
        foreach (char c in p)
        {
            if(!cp.ContainsKey(c))
                cp.Add(c, 1);
            else
                cp[c]++;
        }

        foreach (char c in s)
        {
            if(!cs.ContainsKey(c))
                cs.Add(c, 0);
        }
      
        List<int> ans = new List<int>();

        for(int i =0 ; i<ls; i++)
        {
            cs[s[i]] +=1;
          
            if (i >= lp){
                cs[s[i-lp]] -=1;                
            }
            if (IsDicEqual(cp, cs))
                ans.Add(i - lp + 1);     
        }
        return ans;
    }
    private bool IsDicEqual(Dictionary<char, int> cp, Dictionary<char, int> cs)
    {
        foreach(var kv in cp)
        {
            if(cs.ContainsKey(kv.Key) && kv.Value == cs[kv.Key] )
                continue;
            else
                return false;
        }
        return true;
    }
}


/*
    var s = new Solution438();
    "abab" "ab"
    var result = s.FindAnagrams("cbaebabacd", "abc");
    Console.WriteLine(result);   
*/