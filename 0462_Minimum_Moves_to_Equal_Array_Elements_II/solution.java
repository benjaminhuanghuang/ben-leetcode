package cn.huang.leetcode;
/*
462. Minimum Moves to Equal Array Elements II

Given a non-empty integer array, find the minimum number of moves required to make all array elements equal,
where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

 */


import java.util.Arrays;

/*
https://www.jianshu.com/p/2bb14f0e3d3d

Time Complexity: O(NlogN)    Space Complexity: O(1)
Solution2：quickselect方法找Medium，再求结果
思路：
like 215. Kth Largest Element in an Array
Time Complexity: O(N)    Space Complexity: O(N)
 */
public class LC_0462_MinimumMovestoEqualArrayElements_II {
    public class Solution {
        public int minMoves2(int[] nums) {
            Arrays.sort(nums);
            int i = 0, j = nums.length-1;
            int count = 0;
            while(i < j){
                count += nums[j]-nums[i];
                i++;
                j--;
            }
            return count;
        }
    }

    public int minMoves2(int[] A) {
        int sum = 0, median = quickselect(A, A.length/2+1, 0, A.length-1);
        for (int i=0;i<A.length;i++) sum += Math.abs(A[i] - median);
        return sum;
    }

    public int quickselect(int[] A, int k, int start, int end) {
        int l = start, r = end, pivot = A[(l+r)/2];
        while (l<=r) {
            while (A[l] < pivot) l++;
            while (A[r] > pivot) r--;
            if (l>=r) break;
            swap(A, l++, r--);
        }
        if (l-start+1 > k) return quickselect(A, k, start, l-1);
        if (l-start+1 == k && l==r) return A[l];
        return quickselect(A, k-r+start-1, r+1, end);
    }

    public void swap(int[] A, int i, int j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}
