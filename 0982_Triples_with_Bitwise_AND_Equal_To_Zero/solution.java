package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Hashtable;
import java.util.Map;

/*
982. Triples with Bitwise AND Equal To Zero



Given an array of integers A, find the number of triples of indices (i, j, k) such that:

    0 <= i < A.length
    0 <= j < A.length
    0 <= k < A.length
    A[i] & A[j] & A[k] == 0, where & represents the bitwise-AND operator.



Example 1:

Input: [2,1,3]
Output: 12
Explanation: We could choose the following i, j, k triples:
(i=0, j=0, k=1) : 2 & 2 & 1
(i=0, j=1, k=0) : 2 & 1 & 2
(i=0, j=1, k=1) : 2 & 1 & 1
(i=0, j=1, k=2) : 2 & 1 & 3
(i=0, j=2, k=1) : 2 & 3 & 1
(i=1, j=0, k=0) : 1 & 2 & 2
(i=1, j=0, k=1) : 1 & 2 & 1
(i=1, j=0, k=2) : 1 & 2 & 3
(i=1, j=1, k=0) : 1 & 1 & 2
(i=1, j=2, k=0) : 1 & 3 & 2
(i=2, j=0, k=1) : 3 & 2 & 1
(i=2, j=1, k=0) : 3 & 1 & 2



Note:

    1 <= A.length <= 1000
    0 <= A[i] < 2^16


 */
public class LC_0982_TripleswithBitwiseANDEqualToZero {
    /*
    https://zxi.mytechroad.com/blog/leetcode/leetcode-weekly-contest-121/
    状态压缩
     */
    public int countTriplets(int[] A) {
        int result = 0;
        Hashtable<Integer, Integer> table = new Hashtable<>();
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A.length; j++) {
                int tmp = A[i] & A[j];
                if (!table.containsKey(tmp)) {
                    //System.out.println("set "+tmp+" to 1");
                    table.put(tmp, 1);
                } else {
                    //System.out.println("replare "+tmp+" to "+table.get(tmp)+1);
                    table.replace(tmp, table.get(tmp) + 1);
                }
            }
        }
        for (int i = 0; i < A.length; i++) {
            Integer[] a = new Integer[table.keySet().size()];
            table.keySet().toArray(a);
            for (Integer k : a) {
                if ((A[i] & k) == 0)
                    result += table.get(k);
            }
        }
        return result;
    }
}


