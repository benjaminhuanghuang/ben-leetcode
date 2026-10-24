/*
127. Word Ladder
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest 
transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

*/
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class Solution127
{
    // If I use wordList instead of wordSet, it will be TLE
    // The REASON is HashSet.Contain is MUCH more faster than List.Contain!!!
    public int LadderLength_9(string beginWord, string endWord, IList<string> wordList)
    {
        if (!wordList.Contains(endWord))
            return 0;
        var wordSet = new HashSet<string>(wordList);
        var preVisitedWords = new List<string> { beginWord };
        var level = 1;
        var wordLength = beginWord.Length;

        while (preVisitedWords.Count > 0)
        {
            var nextVisitedWords = new List<string>();
            foreach (var word in preVisitedWords)
            {
                if (word == endWord)
                    return level;

                for (char c = 'a'; c <= 'z'; c++)
                {
                    for (int i = 0; i < wordLength; i++)
                    {
                        if (c != word[i])
                        {
                            char[] chars = word.ToCharArray();
                            chars[i] = c;
                            string nextWord = new string(chars);
                            //if (wordSet.Contains(nextWord))
                            if (wordList.Contains(nextWord))
                            {
                                nextVisitedWords.Add(nextWord);
                                wordSet.Remove(nextWord);
                                wordList.Remove(nextWord);
                            }
                        }
                    }
                }
            }
            preVisitedWords = nextVisitedWords;
            level++;  
        }
        return 0;
    }
    /*
    Solution: Use the graph BFS search. preVisitedStr stores all the up level strings(with same 
    step transformation from start). loop up level strings and find all string only one char 
    different(up level string can transform to this string). 
    Store these strings to up level again(step + 1). and remove all these string from dict. 
    do it over and over again until the up level is empty.
     */
    public int LadderLength(string beginWord, string endWord, IList<string> wordList)
    {
        // You may assume no duplicates in the word list.
        if (!wordList.Contains(endWord))
            return 0;
        var preVisitedStr = new List<string> { beginWord };
        var level = 1;

        while (preVisitedStr.Count != 0)
        {
            var nextVisitedStr = new List<string>();
            foreach (var visited in preVisitedStr)
            {
                if (IsOnlyOneCharDifferent(endWord, visited))
                {
                    return level + 1;
                }

                for (var i = wordList.Count - 1; i >= 0; i--)
                {
                    if (!IsOnlyOneCharDifferent(visited, wordList[i]))
                    {
                        continue;
                    }

                    nextVisitedStr.Add(wordList[i]);
                    wordList.RemoveAt(i);
                }
            }

            preVisitedStr = nextVisitedStr;
            level++;
        }

        return 0;
    }
    private static bool IsOnlyOneCharDifferent(string str1, string str2)
    {
        // all string have same length
        return str1.Where((t, i) => !t.Equals(str2[i])).Count() == 1;
    }

    /*
        derived from LadderLength_1

    */
    public int LadderLength_2(string beginWord, string endWord, IList<string> wordList)
    {
        if (!wordList.Contains(endWord))
            return 0;
        var preVisitedStr = new List<string> { beginWord };
        var level = 1;

        while (preVisitedStr.Count != 0)
        {
            var nextVisitedStr = new List<string>();
            foreach (var visited in preVisitedStr)
            {

                var nextWords = GetNextWords(visited, wordList);
                foreach (string nw in nextWords)
                {
                    if (nw == endWord)
                        return level + 1;

                    if (wordList.Contains(nw))
                    {
                        nextVisitedStr.Add(nw);
                        wordList.Remove(nw);
                    }
                }
            }

            preVisitedStr = nextVisitedStr;
            level++;
        }

        return 0;
    }

    private List<string> GetNextWords(string word, IList<string> dict)
    {
        var nextWords = new List<string>();
        for (char c = 'a'; c <= 'z'; c++)
        {
            for (int i = 0; i < word.Length; i++)
            {
                if (c == word[i])
                {
                    continue;
                }
                char[] chars = word.ToCharArray();
                chars[i] = c;
                string nextWord = new string(chars);
                if (dict.Contains(nextWord))
                {
                    nextWords.Add(nextWord);
                }
            }
        }
        return nextWords;
    }
    /*
        derived from LadderLength_2

    */
    public int LadderLength_3(string beginWord, string endWord, IList<string> wordList)
    {
        if (!wordList.Contains(endWord))
            return 0;
        var preVisitedStr = new List<string> { beginWord };
        var level = 1;

        wordList.Remove(beginWord);
        while (preVisitedStr.Count > 0)
        {
            if (preVisitedStr.Any(s => s == endWord))
            {
                return level;
            }
            preVisitedStr = GetNextMoves(preVisitedStr, wordList);
            level++;
        }
        return 0;
    }

    private List<string> GetNextMoves(List<string> starts, IList<string> dict)
    {
        List<string> nextStarts = new List<string>();
        foreach (var start in starts)
        {
            // use hash to speed up the detection
            for (int i = 0; i < start.Length; i++)
            {
                var charArr = start.ToCharArray();
                for (char c = 'a'; c <= 'z'; c++)
                {
                    charArr[i] = c;
                    string s = new string(charArr);
                    if (dict.Contains(s))
                    {
                        nextStarts.Add(s);
                        dict.Remove(s);
                    }
                }
            }
        }
        return nextStarts;
    }

    public int LadderLength_New(string beginWord, string endWord, IList<string> wordList)
    {
        if (!wordList.Contains(endWord))
            return 0;
        HashSet<string> reached = new HashSet<string>();
        reached.Add(beginWord);
        wordList.Add(endWord);
        int distance = 1;
        while (!reached.Contains(endWord))
        {
            HashSet<string> toAdd = new HashSet<string>();
            foreach (string each in reached)
            {
                for (int i = 0; i < each.Length; i++)
                {
                    char[] chars = each.ToCharArray();
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        chars[i] = ch;
                        string word = new string(chars);
                        if (wordList.Contains(word))
                        {
                            toAdd.Add(word);
                            wordList.Remove(word);
                        }
                    }
                }
            }
            distance++;
            if (toAdd.Count == 0)
                return 0;
            reached = toAdd;
        }
        return distance;
    }
    public int LadderLength(string beginWord, string endWord, ISet<string> wordList)
    {
        HashSet<string> reached = new HashSet<string>();
        reached.Add(beginWord);
        wordList.Add(endWord);
        int distance = 1;
        while (!reached.Contains(endWord))
        {
            HashSet<string> toAdd = new HashSet<string>();
            foreach (string each in reached)
            {
                for (int i = 0; i < each.Length; i++)
                {
                    char[] chars = each.ToCharArray();
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        chars[i] = ch;
                        string word = new string(chars);
                        if (wordList.Contains(word))
                        {
                            toAdd.Add(word);
                            wordList.Remove(word);
                        }
                    }
                }
            }
            distance++;
            if (toAdd.Count == 0)
                return 0;
            reached = toAdd;
        }
        return distance;
    }
}


/*

var s = new Solution127();
var begin = "hit";
var end ="cog";
var wordList = new List<string> {"hot","dot","dog","lot","log"};

var res= s.LadderLength(begin, end, wordList);
Console.WriteLine(res);

 */
