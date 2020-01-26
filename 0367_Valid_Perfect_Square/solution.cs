/*
367. Valid Perfect Square

Given a positive integer num, write a function which returns True if num is a perfect square 
else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
*/

public class Solution367 {
    public bool IsPerfectSquare(int num) {
        if (num < 1)
            return false;
        if (num == 1)
            return true;

        long left = 0;
        long right = num/2;
        while (left <= right)
        {
            long mid = left + ((right - left) >> 1);
            long val = mid * mid;
            if (val == num)
                return true;
            else if (val > num)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
}