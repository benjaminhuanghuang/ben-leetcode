package cn.huang.leetcode;
/*
    942. DI String Match
    Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.

    Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

    If S[i] == "I", then A[i] < A[i+1]
    If S[i] == "D", then A[i] > A[i+1]
 */
public class LC_0942_DIStringMatch {
    public int[] diStringMatch(String S) {
        int[] res = new int[S.length()+1];

        int min = 0;
        int max = S.length();

        for(int i = 0 ; i< S.length();i++)
        {
            if (S.charAt(i) == 'I')
            {
                res[i]= min;
                min++;
            }
            else if(S.charAt(i) == 'D')
            {
                res[i]= max;
                max --;
            }
        }
        res[S.length()] = min;
        return res;
    }
}
