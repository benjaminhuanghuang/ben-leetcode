public class Solution553
{
    public string OptimalDivision(int[] nums)
    {
        string str = "";
        if (nums.Length == 1) return nums[0] + "";
        if (nums.Length == 2) return nums[0] + "/" + nums[1];

        for (int i = 1; i < nums.Length - 1; i++)
        {
            str = str + nums[i] + "/";
        }
        if (nums.Length > 1)
            str = str + nums[nums.Length - 1];
        return nums[0] + "/" + "(" + str + ")";
    }
}