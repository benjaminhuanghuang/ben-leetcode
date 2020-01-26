/*
68. Text Justification
Given an array of words and a length L, format the text such that each line has exactly L characters 
and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a 
line do not divide evenly between words, the empty slots on the left will be assigned more spaces than 
the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
*/

using System;
using System.Linq;
using System.Text;
using System.Collections.Generic;

public class Solution068 {
    public IList<string> FullJustify(string[] words, int maxWidth) {
        var res = new List< string>();
        var oneline = new List< string>();   // words in current line
        var charsCountInLine = 0;
        for (int i = 0; i < words.Length; i++)             
        {                 
            //oneline.Count = the count of the space
            if (charsCountInLine + oneline.Count + words[i].Length > maxWidth)
            {
                var stringbuilder = new StringBuilder();
                var leftSpaces = maxWidth - charsCountInLine;
                for (int j = 0; j < oneline.Count; j++)                     
                {                         
                    stringbuilder.Append(oneline[j]);                         
                    if (j == oneline.Count - 1)                         
                    {                             
                        continue;                         
                    }    
                    // ! how many spaces will be add.                     
                    var spaceToAdd = leftSpaces / (oneline.Count - 1) + 
                                        (leftSpaces % (oneline.Count - 1) > j ? 1 : 0);
                    stringbuilder.Append(' ', spaceToAdd);
                }
                // string PadRight(int totalWidth)
                res.Add(stringbuilder.ToString().PadRight(maxWidth)); 

                charsCountInLine = 0;
                oneline.Clear();
            }

            charsCountInLine += words[i].Length;
            oneline.Add(words[i]);
        }

        if (oneline.Any())
        {
            res.Add(string.Join(" ", oneline).PadRight(maxWidth)); 
        }

        return res;
    }
}

