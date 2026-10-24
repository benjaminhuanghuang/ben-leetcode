using System.Linq;
using System.Collections.Generic;

public class Solution187 {
    public IList<string> FindRepeatedDnaSequences(string s) {
        Dictionary<string, int> pool = new Dictionary<string, int>();
        HashSet<string> res = new HashSet<string>();
        // List<string> res = new List<string>();    // Wrong! 

        for (int i = 0; i < s.Length - 9; i++)
        {
            string dna = s.Substring(i, 10);
            if (pool.ContainsKey(dna))
            {
                res.Add(dna);
            }
            else
            {
                pool.Add(dna, 1);
            }
        }
        return res.ToList<string>();
    }
}