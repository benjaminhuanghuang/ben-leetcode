package cn.huang.leetcode;

/*
287. Find the Duplicate Number
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least
one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2

Example 2:

Input: [3,1,3,4,2]
Output: 3

Note:

    You must not modify the array (assume the array is read only).
    You must use only constant, O(1) extra space.
    Your runtime complexity should be less than O(n2).
    There is only one duplicate number in the array, but it could be repeated more than once.



 */
public class LC_0287_FindtheDuplicateNumber {
    //时间 O(NlogN) 空间 O(1)
    //二分查找,    1..10, 小于等于5的一定有5个,如果多于5个,就在lower part, 等于5个就是upper part.
    // Find the smallest m such that len(nums <= m) > m, which means m is the duplicate number.
    public int findDuplicate(int[] nums) {
        int n = nums.length - 1;
        int low = 1, high = n;
        int mid = 0;

        while (low < high) {
            mid = low + (high - low) / 2;
            int c = count(nums, mid); //moves #numbers less than mid.
            if (c <= mid) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    private int count(int[] nums, int mid) {
        int c = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] <= mid) c++;
        }
        return c;
    }
    /*
    映射找环法:时间 O(N) 空间 O(1)

    链表找环思路：假设快慢指针在环上第k个节点相遇，而环的起点是链表第m个节点，环的总长度是n。此时慢指针再走n-k步就回到了环的开头，
    而此时快指针已经走了m+k步。如果我们这时候将快指针放回起点，并让它也一次走1步，这样当两个节点再次相遇时，相遇点就是环的起点。


     */

    public int findDuplicate_Better(int[] nums) {
        int slow = 0;
        int fast = 0;
        // 找到快慢指针相遇的地方
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        int find = 0;
        // 用一个新指针从头开始，直到和慢指针相遇
        while (find != slow) {
            slow = nums[slow];
            find = nums[find];
        }
        return find;
    }
}
