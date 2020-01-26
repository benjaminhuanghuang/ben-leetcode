/*
318. Maximum Product of Word Lengths

Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where 
the two words do not share common letters. You may assume that each word will contain only 
lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/

using System;

public class Solution318 {
    public int MaxProduct(string[] words) {
        int count = words.Length;
        int[] words_bits = new int[count];

        for(int i=0; i< count; i++)
        {
            foreach (var c in words[i])
            {
                words_bits[i] |= 1 << (c -'a');
            }
        }
        int ans = 0;
        for(int i =0; i< count; i++)
        {
            for(int j= i+1; j < count; j++)
            {
                if((words_bits[i] & words_bits[j]) ==0) // two words do not have common letter
                {
                    ans = Math.Max(ans, words[i].Length * words[j].Length);
                }
            }
        }
        return ans;
    }
}