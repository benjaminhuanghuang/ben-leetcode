/*
9. Palindrome Number
Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.                     

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

*/

public class Solution009 {
    public bool IsPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        int tmp = x;
        int revert = 0;
        while(tmp>0)
        {
            revert = revert * 10 + tmp % 10;
            tmp = tmp / 10;
        }
        return revert == x;
    }
}