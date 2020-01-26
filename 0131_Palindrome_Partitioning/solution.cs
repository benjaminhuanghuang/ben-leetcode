/*
131. Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/

using System.Collections.Generic;

public class Solution131 {
    //https://miafish.wordpress.com/2015/01/31/leetcode-oj-c-palindrome-partitioning/
    public IList<IList<string>> Partition(string s) {
         return PartitionRecursion(s, 0);
    }

    private IList<IList<string>> PartitionRecursion(string s, int index)
    {
        var res = new List<IList<string>>();

        if (index >= s.Length)
        {
            res.Add(new List<string>{});
            return res;
        }

        for (int endOfSubString = index; endOfSubString < s.Length; endOfSubString++)
        {
            var str = s.Substring(index, endOfSubString - index + 1); // index to the end
            if (isPalindrom(str))
            {
                var restPartitions = PartitionRecursion(s, endOfSubString + 1);

                foreach (var restPartition in restPartitions)
                {
                    var newPartition = new List<string> {str};
                    newPartition.AddRange(restPartition);
                    res.Add(newPartition);
                }
            }
        }

        return res;
    }

    private bool isPalindrom(string str)
    {
        for (int i = 0, j = str.Length - 1; i < j; i++, j--)
        {
            if (str[i] != str[j])
            {
                return false;
            }
        }

        return true;
    }
}