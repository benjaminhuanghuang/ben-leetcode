
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;

public class LeetTest
{
    public static void Main(string[] args)
    {
        string[] input = new string[] { "aba", "cdc", "eae" };
        var s = new Solution522();
        Console.WriteLine(s.FindLUSlength(input));
    }
}