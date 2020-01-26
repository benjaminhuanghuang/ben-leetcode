/*
388. Longest Absolute File Path

Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.

Note:
The name of a file contains at least a . and an extension.
The name of a directory or sub-directory will not contain a ..
Time complexity required: O(n) where n is the size of the input string.

Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
*/

using System;
using System.Collections.Generic;

public class Solution388
{
    public int LengthLongestPath(string input)
    {
        int maxlen = 0;
        // hold length of each depth in one line
        Dictionary<int, int> pathlen = new Dictionary<int, int>();
        pathlen.Add(0, 0);
        foreach (string line in input.Split('\n'))
        {
            //  Remove all '\t' from line, python: name = line.lstrip('\t')
            string name = line.Replace("\t", "");
            int depth = line.Length - name.Length;
            if (name.IndexOf('.') >= 0)
                maxlen = Math.Max(maxlen, pathlen[depth] + name.Length);
            else
                pathlen[depth + 1] = pathlen[depth] + name.Length + 1;
        }
        return maxlen;
    }

    // def lengthLongestPath_2(self, input):
    //     """
    //     :type input: str
    //     :rtype: int
    //     """
    //     ans = lengthSum = 0
    //     stack = [(-1, 0)]
    //     for p in input.split('\n'):
    //         depth = p.count('\t')
    //         name = p.replace('\t', '')
    //         topDepth, topLength = stack[-1]
    //         while depth <= topDepth:
    //             stack.pop()
    //             lengthSum -= topLength
    //             topDepth, topLength = stack[-1]
    //         length = len(name) + (depth > 0)
    //         lengthSum += length
    //         stack.append((depth, length))
    //         if name.count('.'):
    //             ans = max(ans, lengthSum)
    //     return ans
}

/*
string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
var s = new Solution388();
var result = s.LengthLongestPath(input);  

Console.WriteLine(result);

*/
