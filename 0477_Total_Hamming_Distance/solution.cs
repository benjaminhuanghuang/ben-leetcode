public class Solution477
{
    /*
    对于一个数组中，全部数字二进制的任意一位，汉明距离的总和为1的个数乘以0的个数。而数组中的数皆为int类型，所以一共需要进行32次循环。
     */
    public int TotalHammingDistance(int[] nums)
    {
        int sum = 0;
        for (int i = 0; i < 32; i++)
        {
            int ones = 0;
            for (int j = 0; j < nums.Length; j++)
                ones += (nums[j] >> i) & 0x1;
            sum += ones * (nums.Length - ones);
        }
        return sum;
    }
}