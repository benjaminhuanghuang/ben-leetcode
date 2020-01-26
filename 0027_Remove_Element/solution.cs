/*
27. Remove Element
# 26. Remove Duplicates from Sorted Array
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.


Next challenges: (M) Shortest Word Distance III  (M) Find the Celebrity  (M) Wiggle Sort

*/

public class Solution027 {
    public int RemoveElement(int[] nums, int val) {
        if (nums == null)
            return 0;
        int len = nums.Length;
        
        int i = 0;
        int right = len - 1;
        while (i <= right)
        {   
            int curr = nums[i]; 
            if ( curr == val )
            {
                this.SwapArrayElements(nums, i, right);
                right --;    
            }
            else
            {
                i ++;
            }
        }
        return i;
    }
    public void SwapArrayElements(int[] nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp; 
    }

    // use two pointers too, i from -1, j from begin too. 
    // iterate j from start to end, if value of j is what we want to find, swap it with i+1.
    public int RemoveElement_2(int[] nums, int val)
    {
        var i = -1;
        for (int j = 0; j < nums.Length; j++)
        {
            if (nums[j] != val)
            {
                var temp = nums[j];
                nums[j] = nums[++i];
                nums[i] = temp;
            }
        }

        return i + 1;
    }
}