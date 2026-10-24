/*
http://www.liuchuo.net/archives/3716
遍历Diction中的某一个word，设当前字符串的下标为index，对于当前字符串dict[index]，
使用两个指针i和j分别从头到尾遍历s和dict[index]，随着i指针的增加，如果j指针所指元素和i指针所指元素相同
就向后移动一位，当i指针都指完的时候，j如果也指完了,说明当前dict[index]是s的子串，
如果当前d[index]的长度比保存的result字符串长度长，就更新result，或者一样长,但是字典序排列中d[index]
比result小，也要更新result，最后返回result
*/
using System;
using System.Collections.Generic;
public class Solution524
{
    public string FindLongestWord(string s, IList<string> dictionary)
    {
        // Can not sort IList<string>
        List<string> soredDict = new List<string>(dictionary);
        soredDict.Sort();
        string result = "";
        foreach (var word in soredDict)
        {
            int i = 0, j = 0;
            for (; i < s.Length && j < word.Length; i++)
            {
                if (s[i] == word[j])
                    j++;
            }
            if (j == word.Length && result.Length < word.Length)
            {
                result = word;
            }
        }
        return result;
    }
}

