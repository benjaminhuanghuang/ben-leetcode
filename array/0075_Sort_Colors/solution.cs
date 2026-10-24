public class Solution075 {
      public void SortColors(int[] nums) {

        for (int start = 0, end = nums.Length - 1, i = start; i <= end;)
        {
            if (nums[i] == 0)
            {
                if (i == start)
                {
                    i++;
                    start++;
                }
                else
                {
                    this.Swap(nums, i, start++);      
                }
            }
            else if (nums[i] == 1)
            {
                i++;
            }
            else
            {
                this.Swap(nums , i, end--);
            }
        }
    }

    private void Swap(int[] nums, int i, int j)
    {
        int tmp = nums[j];
        nums[j] = nums[i];
        nums[i] = tmp;
    }
}