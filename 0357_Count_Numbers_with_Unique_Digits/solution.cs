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
