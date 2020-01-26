package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;

/*
961. N-Repeated Element in Size 2N Array


 */
public class LC_0961_NRepeatedElementinSize2NArray {
    public int repeatedNTimes(int[] A) {
        Map<Integer, Integer> count = new HashMap<Integer, Integer>();
        for(int i=0; i<A.length; i++)
        {
            if(count.containsKey(A[i]))
            {
                count.put(A[i], count.get(A[i])+1);
            }
            else
            {
                count.put(A[i],1);
            }
        }

        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            if (entry.getValue() ==  A.length / 2) {
                return entry.getKey();
            }
        }
        return -1;
    }
}
