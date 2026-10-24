/*
275. H-Index II

Follow up for H-Index: What if the citations array is sorted in ascending order? 
Could you optimize your algorithm?

Hint:

Expected runtime complexity is in O(log n) and the input is sorted.

*/

public class Solution275 {
    //https://segmentfault.com/a/1190000003794831
    public int HIndex(int[] citations) {
        int n = citations.Length;
        if(n == 0) return 0;
        int min = 0, max = citations.Length - 1;
        while(min <= max){
            int mid = (min + max) / 2;
            // 如果该点是有效的H指数，则最大H指数一定在右边
            if(citations[mid] < n - mid){
                min = mid + 1;
            // 否则最大H指数在左边
            } else {
                max = mid - 1;
            }
        }
        // n - min是min点的H指数
        return n - min;
    }
}