using System;
public class Solution372 {
    //c % m = (a * b) % m  = [(a % m) * (b % m)] % m
    public int SuperPow_Overflow(int a, int[] b) {
        double ans = 1;
        double dbA = (double)a;
        int mod = 1337;

        for(int i = b.Length - 1 ; i >= 0 ;i --) 
        {
            // ans = ans * a ^ bi % m 
            ans = ans * Math.Pow(dbA ,b[i]) % mod;
            dbA = Math.Pow(dbA, 10) % mod; 
        }
        return (int)ans;
    }

    public int SuperPow(int a, int[] b) {
        int result=1;
 
        for(int i=0; i< b.Length; i++){
            result = PowHelper(result, 10) * PowHelper(a, b[i]) % 1337; // result^10 
        }
    
        return result;
    }

    public int PowHelper(int x, int n)
    {
        if(n==0)
            return 1;
        if(n==1)
            return x%1337;
 
        return PowHelper(x%1337, n/2) * PowHelper(x%1337,n-n/2)%1337;   
    }
}