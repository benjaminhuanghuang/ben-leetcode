/*
30. Substring with Concatenation of All Words

You are given a string, s, and a list of words, words, that are all of the same length. 
Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly 
once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

reference:
    https://miafish.wordpress.com/2015/04/10/leetcode-ojc-substring-with-concatenation-of-all-words/
*/
using System.Linq;
using System.Collections;
using System.Collections.Generic;

public class Solution030 {
    // use hash table to store words in words as key and its as value. 
    // then scan s from 0 to the end of string. from i to i + word’s length, 
    // i + word’s length + 1 to i +  2*word’s length, and so on. until all the values in hash table are 0s.
    public IList<int> FindSubstring(string s, string[] words) {
        var res = new List<int>();
        if (words.Length <= 0)
        {
            return res;
        }

        var hashtable = new Dictionary<string, int>();
        // init word-times dictionary
        foreach (var word in words)
        {
            if (!hashtable.ContainsKey(word))
                hashtable.Add(word, 1);
            else
                hashtable[word]++;
        }

        int wordLen = words[0].Length;
        int wordsCount = words.Length; 
        int subStrLen = wordsCount * wordLen;

        for (int i = 0; i < s.Length - subStrLen + 1; i++)
        {
            if (hashtable.ContainsKey(s.Substring(i, wordLen))) // if find any word in words
            {
                // copy hashtable
                var newHashTable = new Dictionary<string, int>(hashtable);
                for (int j = i; j < i + subStrLen; j += wordLen)
                {   // check char from i to i + subStrLen                    
                    var str = s.Substring(j, wordLen); // pick one word
                    if (!newHashTable.ContainsKey(str))
                    {                             
                        break;                         
                    }                         
                    newHashTable[str]--;                     
                }           
                // All newHashTable[word] == 0           
                if (newHashTable.Values.All(value => value == 0))
                {
                    res.Add(i);
                }
            }
        }
        return res;
    }

    public List<int> FindSubstring_2(string s, string[] words) {
        var res = new List<int>();
        var len = words[0].Length;
        var dict = new Dictionary<string, int>();
        foreach (var word in words)
        {
            if (dict.ContainsKey(word))
            {
                dict[word]++;
            }
            else
            {
                dict.Add(word, 1);
            }
        }

        for (int i = 0; i < len; i++)
        {
            var start = i;
            var count = 0;
            var dictword = new Dictionary<string, int>();
            for (int j = i; j + len <= s.Length; j += len)                 
            {                     
                var cur = s.Substring(j, len);                     
                if (!dict.ContainsKey(cur))                     
                {                         
                    dictword.Clear();                         
                    count = 0;                         
                    start = j + len;                         
                    continue;                     
                }                     
                if (dictword.ContainsKey(cur))                     
                {                         
                    dictword[cur]++;                     
                }                     
                else                     
                {                         
                    dictword.Add(cur, 1);                     
                }                     
                if (dictword[cur] > dict[cur])
                {
                    while (start < j)
                    {
                        var pre = s.Substring(start, len);
                        if (dictword.ContainsKey(pre))
                        {
                            dictword[pre]--;
                            if (dictword[pre] < dict[pre])
                            {
                                count--;
                            }
                        }
                        start += len;
                        if (pre == cur) break;
                    }
                }
                else
                {
                    count++;
                }

                if (count == words.Length)
                {
                    res.Add(start);
                    
                    // remove the left one
                    var left = s.Substring(start, len);
                    if (dictword.ContainsKey(left))
                    {
                        dictword[left]--;
                    }
                    count--;
                    start += len;
                }
            }

        }

        return res;
    }
}