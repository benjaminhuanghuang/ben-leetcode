using System;

public class Solution521
{
    public int FindLUSlength(string a, string b)
    {
        int lenA = a.Length;
        int lenB = b.Length;
        if (lenA != lenB)
            return Math.Max(lenA, lenB);
        else
        {
            if (a != b)
                return lenA;
            else
                return -1;
        }
    }
}