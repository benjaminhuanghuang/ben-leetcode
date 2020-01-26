package cn.huang.leetcode;
/*

866. Prime Palindrome

Find the smallest prime palindrome greater than or equal to N.

Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1.

For example, 2,3,5,7,11 and 13 are primes.

Recall that a number is a palindrome if it reads the same from left to right as it does from right to left.

For example, 12321 is a palindrome.



Example 1:

Input: 6
Output: 7

Example 2:

Input: 8
Output: 11

Example 3:

Input: 13
Output: 101



Note:

    1 <= N <= 10^8
    The answer is guaranteed to exist and be less than 2 * 10^8.



 */
public class LC_0866_PrimePalindrome {
    /*
        https://blog.csdn.net/yanglingwell/article/details/80961049
     */
    int primePalindrome(int N) {
        while(!isPalindrome(N) || !isPrime(N))
        {
            ++N;

            // 跳过偶数位数, 偶数位的回文数都能被 11 整除
            if(N > Math.pow(10, 1) && N < Math.pow(10, 2) && N != 11) N = (int)Math.pow(10, 2);
            if(N > Math.pow(10, 3) && N < Math.pow(10, 4)) N = (int)Math.pow(10, 4);
            if(N > Math.pow(10, 5) && N < Math.pow(10, 6)) N = (int)Math.pow(10, 6);
            if(N > Math.pow(10, 7) && N < Math.pow(10, 8)) N = (int)Math.pow(10, 8);
        }

        return N;
    }
    // 判断 num 是否是素数
    boolean isPrime(int num)
    {
        if(num < 2) return false;

        for(int i = 2; i <= Math.sqrt(num); ++i)
        {
            if(num % i == 0) return false;
        }

        return true;
    }
    // 判断 num 是否是回文数
    boolean isPalindrome(int num)
    {
        String orgNumStr = String.valueOf(num);
        int left = 0;
        int right = orgNumStr.length() -1;
        while(left <=right)
        {
            if(orgNumStr.charAt(left) != orgNumStr.charAt(right))
                return false;
            left++;
            right--;
        }
        return true;
    }

}
