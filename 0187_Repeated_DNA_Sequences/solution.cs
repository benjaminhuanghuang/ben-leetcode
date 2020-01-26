/*
187. Repeated DNA Sequences [M]

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify 
repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more 
than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/
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