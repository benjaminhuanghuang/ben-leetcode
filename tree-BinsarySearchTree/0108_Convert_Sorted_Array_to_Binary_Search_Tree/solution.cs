/*
108. Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

public class Solution108 {
    public TreeNode SortedArrayToBST(int[] nums) {
         return this.sortedArrayToBSTRecursion(nums, 0, nums.Length - 1);
    }


    private TreeNode sortedArrayToBSTRecursion(int[] nums, int low, int high)
    {
        if (low > high)
        {
            return null;
        }

        var mid = (high - low) / 2 + low;

        var newRoot = new TreeNode(nums[mid])
                        {
                            left = this.sortedArrayToBSTRecursion(nums, low, mid - 1),
                            right = this.sortedArrayToBSTRecursion(nums, mid + 1, high)
                        };

        return newRoot;
    }
}

