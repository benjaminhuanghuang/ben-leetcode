/*
507. Perfect Number

We define the Perfect Number is a positive integer that is equal to the sum of all its positive 
divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false 
when it is not.

Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Note: The input number n will not exceed 100,000,000. (1e8)


 */

public class Solution507
{
    public bool CheckPerfectNumber(int num)
    {
        int total = 1;
        int div = 2;
        while (div * div <= num)
        {
            if ((num % div) == 0)
            {
                total += div;
                if (div * div != num)
                    total += num / div;
            }
            div++;
        }
        return num > 1 && total == num;
    }
}