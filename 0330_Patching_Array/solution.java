package cn.huang.leetcode;

/*
330. Patching Array

Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in
range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.

Example 1:

Input: nums = [1,3], n = 6
Output: 1
Explanation:
Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.

Example 2:

Input: nums = [1,5,10], n = 20
Output: 2
Explanation: The two patches can be [2, 4].

Example 3:

Input: nums = [1,2,2], n = 5
Output: 0


*/
public class LC_0330_PatchingArray {
    /*
    用一个 miss 数来假设数组中取不到这个数，然后再从数组中从小到大逐一取出一个数 nums[i] 跟 miss 进行比较。
    如果 miss <= nums[i] ，那么说明用 nums[0],nums[1]...nums[i]（可能有些补丁），可以覆盖到 miss + nums[i] - 1，
    那么下面就假设补丁为 miss + nums[i]。
    如果 miss > nums[i]，则说明用 nums[0],nums[1]...nums[i-1]（可能有些补丁），
    不可以覆盖到 miss，那么假设下一个缺失的补丁为 miss * 2：

     */
    public int minPatches(int[] nums, int n) {
        int i = 0;
        long miss = 1;
        int count = 0;
        while (miss <= n) {
            if (i < nums.length && nums[i] <= miss)
                miss += nums[i++];
            else {
                miss = miss << 1;
                count++;
            }
        }
        return count;
    }
}
