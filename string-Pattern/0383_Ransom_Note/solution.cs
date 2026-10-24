/*
383. Ransom Note

Given  an  arbitrary  ransom  note  string  and  another  string  containing  letters from  all  the  magazines,  
write  a  function  that  will  return  true  if  the  ransom   note  can  be  constructed  from  the  magazines ;  otherwise,  it  will  return  false.   

Each  letter  in  the  magazine  string  can  only  be  used  once  in  your  ransom  note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

public class Solution383 {
    // Much better than using Dictionary.
    public bool CanConstruct(string ransomNote, string magazine) {
        int[] cnt = new int[26];
        for (int i = 0; i < magazine.Length; i++) {
            cnt[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.Length; i++) {
            if(cnt[ransomNote[i]-'a'] -- < 0) {
                return false;
            }
        }
        return true;
    }
}