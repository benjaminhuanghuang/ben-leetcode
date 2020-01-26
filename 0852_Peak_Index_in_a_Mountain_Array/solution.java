package cn.huang.leetcode;

/*
 	852	 Peak Index in a Mountain Array
 */
public class LC_0852_PeakIndexinMountainArray {
    public int peakIndexInMountainArray(int[] A) {
        int left = 0;
        int right = A.length - 1;

        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if( A[mid -1] < A[mid] && A[mid]<A[mid+1])
                left = mid;
            else if ( A[mid -1] > A[mid] && A[mid]>A[mid+1])
                right = mid;
            else
                break;
        }
        return mid;
    }
}
