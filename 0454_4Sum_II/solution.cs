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