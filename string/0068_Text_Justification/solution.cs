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

