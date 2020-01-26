/*
345. Reverse Vowels of a String

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".

*/

public class Solution345 {
    public string ReverseVowels(string s) {
        var strarr = s.ToCharArray();
        for (int start = 0, end = s.Length - 1; start < end;)
        {
            while (start < end && "aeiouAEIOU".IndexOf(strarr[start]) < 0)
            {
                start++;
            }

            while (start < end && "aeiouAEIOU".IndexOf(strarr[end]) < 0)
            {
                end--;
            }

            this.Swap(strarr, start, end);
            start++;
            end--;
        }

        return new string(strarr);
    }

    public void Swap(char[] nums, int i, int j)
    {
        char tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp; 
    }
}