/*
165. Compare Version Numbers

Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/
using System;

public class Solution165 {
    public int CompareVersion(string version1, string version2) {
        string[] v1= version1.Split('.');
        string[] v2= version2.Split('.');

        for (int i = 0; i < Math.Max(v1.Length, v2.Length); i++)
        {
            var num1 = int.Parse(i < v1.Length ? v1[i] : "0");
            var num2 = int.Parse(i < v2.Length ? v2[i] : "0");

            if (num1 < num2)                 
            {                     
                return -1;                 
            }                 
            if (num1 > num2)
            {
                return 1;
            }
        }

        return 0;
    }
}