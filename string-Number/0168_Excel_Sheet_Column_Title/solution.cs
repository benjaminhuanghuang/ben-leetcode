/*
168. Excel Sheet Column Title

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/
using System.Text;

public class Solution168 {
    public string ConvertToTitle(int n) {
        var stringbuilder = new StringBuilder();
        while (n > 0)
        {
            stringbuilder.Insert(0, (char)((n - 1) % 26 + 'A'));
            n = (n - 1) / 26;
        }

        return stringbuilder.ToString();
    }
}