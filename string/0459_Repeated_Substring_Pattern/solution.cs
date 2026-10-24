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