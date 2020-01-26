/*
287. Find the Duplicate Number

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, 
find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n^2).
There is only one duplicate number in the array, but it could be "repeated more than once".
*/


public class Solution287 {
    //二分查找,    1..10, 小于等于5的一定有5个,如果多于5个,就在lower part, 等于5个就是upper part. 
    public int FindDuplicate(int[] nums) {
        int n = nums.Length - 1;  
        int low = 1, high= n;  
        int mid = 0;  
        while(low<high) {  
            mid = low + (high-low)/2;  
            int c= count(nums, mid); //count #numbers less than mid.  
            if(c<=mid) {  
                low = mid+1;  
            } else {  
                high = mid;  
            }  
        }  
        return low;  
    }

    private int count(int[] nums, int mid) {  
        int c = 0;  
        for(int i=0; i<nums.Length; i++) {  
            if(nums[i]<=mid) c++;  
        }  
        return c;  
    }  
}