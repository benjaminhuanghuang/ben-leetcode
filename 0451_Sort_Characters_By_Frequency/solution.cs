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
