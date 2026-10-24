public class Solution523
{
    public bool CheckSubarraySum(int[] nums, int k)
    {
        for (int i = 0; i < nums.Length - 1; i++)
        {
            int sum = nums[i];
            for (int j = i + 1; j < nums.Length; j++)
            {
                sum += nums[j];
                if (sum == k)   // for case nums=[0,0], k = 0
                    return true;
                if (k != 0 && sum % k == 0)
                    return true;
            }
        }
        return false;
    }
}