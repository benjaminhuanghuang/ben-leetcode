using System.Collections.Generic;

public class Solution290 {
    public bool WordPattern(string pattern, string str) {
        var dict = new Dictionary<char, string>();
        var dict2 = new Dictionary<string, char>();
        
        string[] sections = str.Split(' ');
        if (sections.Length != pattern.Length)
            return false;

        for(int i=0; i< pattern.Length; i++)
        {
            if(!dict.ContainsKey(pattern[i]))
            {
                dict.Add(pattern[i], sections[i]);
            }
            else
            {
                if(dict[pattern[i]] !=sections[i])
                    return false;
            }
            if(!dict2.ContainsKey(sections[i]))
            {
                dict2.Add(sections[i],pattern[i]);
            }
            else
            {
                if(dict2[sections[i]] !=pattern[i])
                    return false;
            }
        }
        return true;
    }
}