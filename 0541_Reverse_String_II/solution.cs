using System;
public class Solution541
{
    public string ReverseStr(string s, int k)
    {
        if (s == null || s.Length == 0)
            return s;

        char[] charArray = s.ToCharArray();
        int start = 0;
        int end = Math.Min(k - 1, s.Length - 1);
        bool needReverse = true;
        while (start < s.Length - 1)
        {
            if (needReverse)
            {
                Reverse(charArray, start, end);
            }
            needReverse = !needReverse;
            start = Math.Min(start + k, s.Length - 1);
            end = Math.Min(end + k, s.Length - 1);
        }
        return new String(charArray);
    }

    private void Reverse(char[] charArr, int start, int end)
    {
        while (start < end)
        {
            char temp = charArr[start];
            charArr[start] = charArr[end];
            charArr[end] = temp;
            start++;
            end--;
        }
    }
}