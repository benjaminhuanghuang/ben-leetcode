/*
556. Next Greater Element III

Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly 
the same digits existing in the integer n and is greater in value than n. If no such positive 
32-bit integer exists, you need to return -1.

Example 1:
Input: 12
Output: 21
Example 2:
Input: 21
Output: -1

 */

using System;
public class Solution556
{
    public int NextGreaterElement(int n)
    {
        char[] number = n.ToString().ToCharArray();

        int i, j;
        // I) Start from the right most digit and 
        // find the first digit that is
        // smaller than the digit next to it.
        for (i = number.Length - 1; i > 0; i--)
            if (number[i - 1] < number[i])
                break;

        // If no such digit is found, its the edge case 1.
        if (i == 0)
            return -1;

        // II) Find the smallest digit on right side of (i-1)'th 
        // digit that is greater than number[i-1]
        int x = number[i - 1], smallest = i;
        for (j = i + 1; j < number.Length; j++)
            if (number[j] > x && number[j] <= number[smallest])
                smallest = j;

        // III) Swap the above found smallest digit with 
        // number[i-1]
        char temp = number[i - 1];
        number[i - 1] = number[smallest];
        number[smallest] = temp;

        // IV) Sort the digits after (i-1) in ascending order
        Array.Sort(number, i, number.Length);

        long val = long.Parse(new string(number));
        return (val <= int.MaxValue) ? (int)val : -1;
    }
}