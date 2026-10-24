/*
202. Happy Number

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the sum of the squares of its digits, 
and repeat the process until the number 
equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

using System.Collections.Generic;

public class Solution202 {
    public bool IsHappy(int n) {
        var visited = new Dictionary<int, bool>();
        var next = n;

        while (!visited.ContainsKey(next))
        {
            visited.Add(next, true);
            var start = next;
            next = 0;

            while (start != 0)
            {   
                int digit = start % 10;
                next += digit * digit;
                start /= 10;
            }

            if (next == 1) 
                return true;
        }

        return false;
    }
}