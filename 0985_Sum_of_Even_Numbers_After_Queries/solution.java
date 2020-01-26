package cn.huang.leetcode;

/*
985. Sum of Even Numbers After Queries

We have an array A of integers, and an array queries of queries.

For the i-th query val = queries[i][0], index = queries[i][1], we add val to A[index].
Then, the answer to the i-th query is the sum of the even values of A.

(Here, the given index = queries[i][1] is a 0-based index, and each query permanently modifies the array A.)

Return the answer to all queries.  Your answer array should have answer[i] as the answer to the i-th query.



Example 1:

Input: A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
Output: [8,6,2,4]
Explanation:
At the beginning, the array is [1,2,3,4].
After adding 1 to A[0], the array is [2,2,3,4], and the sum of even values is 2 + 2 + 4 = 8.
After adding -3 to A[1], the array is [2,-1,3,4], and the sum of even values is 2 + 4 = 6.
After adding -4 to A[0], the array is [-2,-1,3,4], and the sum of even values is -2 + 4 = 2.
After adding 2 to A[3], the array is [-2,-1,3,6], and the sum of even values is -2 + 6 = 4.


Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
1 <= queries.length <= 10000
-10000 <= queries[i][0] <= 10000
0 <= queries[i][1] < A.length

 */
public class LC_0985_SumofEvenNumbersAfterQueries {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int count = queries.length;

        int[] ans = new int[count];

        for (int i = 0; i < count; i++) {
            A[queries[i][1]] = A[queries[i][1]] + queries[i][0];
            ans[i] = getEvenSum(A);
        }
        return ans;
    }

    private int getEvenSum(int[] A) {
        int sum = 0;
        for (int n : A) {
            if (n % 2 == 0)
                sum += n;
        }
        return sum;
    }

    /*
        https://www.youtube.com/watch?v=5xL_N2S3-QU
     */
    public int[] sumEvenAfterQueries_huahua(int[] A, int[][] queries) {
        int sum = 0;
        for (int i = 0; i < A.length; ++i)
            if (A[i] % 2 == 0)
                sum += A[i];
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int a = A[queries[i][1]];
            if (a % 2 == 0)
                sum -= a;
            a += queries[i][0];
            if (a % 2 == 0)
                sum += a;
            ans[i] = sum;
        }
        return ans;
    }
}
