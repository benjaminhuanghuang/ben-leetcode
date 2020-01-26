/*
372. Super Pow

Your task is to calculate a^b mod 1337 where a is a positive integer and b is an extremely 
large positive integer given in the form of an array.

Example1:

a = 2
b = [3]

Result: 8
Example2:

a = 2
b = [1,0]

Result: 1024

*/
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