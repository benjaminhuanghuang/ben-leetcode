/*
357. Count Numbers with Unique Digits

Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, 
excluding [11,22,33,44,55,66,77,88,99])

Hint:

*/

public class Solution357 {
    public int CountNumbersWithUniqueDigits(int n) {
        int[] dp = new int[n+1];
        dp[0]=1; // x can be 0
    
        for(int i=1; i<=n; i++){
            dp[i]=9;
            for(int j=9; j>=9-i+2; j--){
                dp[i] *= j;
            }
        }
    
        int result =0;
        foreach(int i in dp)
            result += i;
    
        return result;
    }
}
