public class Solution283 {
    public void MoveZeroes(int[] nums) {
        int pivot = 0;
        for( int i =0 ; i < nums.Length; i++)
        {
            if(nums[i] != 0)
            {
                nums[pivot] = nums[i];
                pivot ++;
            }
        }

        for (int i = pivot; i< nums.Length; i++)
        {
            nums[i] = 0;
        }
    }
}
