/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

*/

public class Solution014 {
    public string LongestCommonPrefix(string[] strs) {
        if(strs == null || strs.Length == 0)  
        {  
            return "";  
        }  
        for(int i=0; i<strs[0].Length; i++)  
        {  
            for(int j=1; j<strs.Length; ++j)  
            {  
                if(strs[j].Length<=i||strs[j][i]!=strs[0][i])  
                {  
                    return strs[0].Substring(0,i);  
                }  
            }               
        }  
        return strs[0];  
    }
}