/*
459. Repeated Substring Pattern

Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple 
copies of the substring together. You may assume the given string consists of lowercase English letters 
only and its length will not exceed 10000.

Example 1:
    Input: "abab"
    Output: True

    Explanation: It's the substring "ab" twice.
Example 2:
    Input: "aba"
    Output: False

Example 3:
    Input: "abcabcabcabc"
    Output: True
    Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/

/*
def repeatedSubstringPattern(self, str):
    size = len(str)
    for x in range(1, size / 2 + 1):
        if size % x:
            continue
        if str[:x] * (size / x) == str:
            return True
    return False
*/
public class Solution459 {
    public bool RepeatedSubstringPattern(string str) 
    {        
        if(str.Length < 2) 
            return false;        
        int subLen = 1;        
        while(subLen <= str.Length/2)
        {            
            if(str.Length % subLen ==0)
            {                
                if(check(str,subLen))           
                    return true;  
            }
            subLen++;
        }       
        return false;
    }   

    public bool check(string str,int subLength)
    {       
        int n = str.Length / subLength;
        for(int i = 0; i < n - 1;i ++)
        {            
            for(int j = 0; j < subLength; j++) 
            {               
                if(str[ i*subLength + j] != str[(i+1)*subLength + j])
                    return false;;        
            }        
        }
        return true;
    }
}

/*
var s = new Solution459();
var result = s.RepeatedSubstringPattern("abab"); 

Console.WriteLine(result);
*/