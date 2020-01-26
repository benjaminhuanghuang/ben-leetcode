/*
189. Rotate Array  [E]

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II (#186)

*/

public class Solution189 {
    public void Rotate(int[] nums, int k) {
        if (k <= 0)
            return;

        int len = nums.Length;
        k %= len;

        // reverse first part
        this.reverseBetween(nums, 0, len - k - 1);
        // reverse second part
        this.reverseBetween(nums, len - k, len - 1);
        // reverse whole list
        this.reverseBetween(nums, 0, len - 1);
    }

     public void reverseBetween(int[] s, int i, int j)
     {
        while(i<j){
            int temp = s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }
    }
}