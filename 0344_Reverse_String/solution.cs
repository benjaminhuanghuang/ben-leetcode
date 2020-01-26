/*
344. Reverse String

Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/


public class Solution344 {
    public string ReverseString(string s) {
        if (s.Length == 0)
            return s;
        var strArray = s.ToCharArray();
        int l =0, r = s.Length -1;
        //   Array.Reverse(strarr);
        while(l<r)
        {
            char tmp = strArray[l];
            strArray[l] = strArray[r];
            strArray[r] = tmp;
            l++;
            r--;
        }
        return new string(strArray);
    }
}