package cn.huang.leetcode;

/*

992. Subarrays with K Different Integers [Hard] [#340, #793]

Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number
of different integers in that subarray is exactly K.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of A.



Example 1:

Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
Example 2:

Input: A = [1,2,1,3,4], K = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].


Note:

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length
 */
public class LC_0992_SubarrayswithKDifferentIntegers {
    /*
     Time O(N)
     Space O(N)
     */
    public int subarraysWithKDistinct(int[] A, int K) {
        return subarrays(K, A) - subarrays(K - 1, A);
    }

    // Return the number of subarrays with K or less distinct numbers
    private int subarrays(int k, int[] A) {
        int[] count = new int[A.length + 1];
        int ans = 0;
        int i = 0;
        for (int j = 0; j < A.length; j++) {
            if(count[A[j]]++ == 0)
            {
                --k;
            }
            while(k < 0) {
                if (count[A[i++]] == 0)
                    ++k;
            }
            ans += j- i +1;
        }
        return ans;
    }
}
