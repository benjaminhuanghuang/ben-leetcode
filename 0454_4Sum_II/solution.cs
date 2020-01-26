/*
454. 4Sum II

Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that 
A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are 
in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/
using System.Collections.Generic;

public class Solution454 {
    public int FourSumCount(int[] A, int[] B, int[] C, int[] D) {
        Dictionary<int, int> ans = new Dictionary<int, int>();
        int count = 0;
        foreach(int a in A)
        {
            foreach(int b in B)
            {
                int sum = a + b;
                if(ans.ContainsKey(sum))
                {
                    ans[sum]++;
                }
                else
                {
                    ans.Add(sum, 1);
                }
            }
        }
        foreach(int c in C)
        {
            foreach(int d in D)
            {
                int sum = c + d;
                if(ans.ContainsKey(-sum))
                    count += ans[-sum];
            }
        }
        
        return count;
    }
}