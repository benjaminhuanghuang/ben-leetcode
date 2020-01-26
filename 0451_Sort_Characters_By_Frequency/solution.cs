/*
451. Sort Characters By Frequency [Google Amazon] 

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/
using System.Collections.Generic;
using System.Text;
using System.Linq;

public class Solution451 {
    public string FrequencySort(string s) {
        var dic = new Dictionary<char, int>();

        foreach (char c in s)
        {
            if (dic.ContainsKey(c))
            {
                dic[c]++;
            }
            else
            {
                dic.Add(c, 1);
            }
        }
        // Key point
        var sortedDic = dic.OrderByDescending(kv => kv.Value);
        var sb = new StringBuilder();
        foreach (var kv in sortedDic)
        {
            for(int i = 0; i < kv.Value; i++)
                sb.Append(kv.Key);
        }
        return sb.ToString();
    }
}
