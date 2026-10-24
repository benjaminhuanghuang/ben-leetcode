/*
171. Excel Sheet Column Number

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

public class Solution171 {
    public int TitleToNumber(string s) {
        int res = 0;
        for (int i =0 ; i< s.Length; i++)
        {
            res = res* 26 + s[i] - 'A' + 1; 
        }
        return res;
    }
}