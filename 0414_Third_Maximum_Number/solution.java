package cn.huang.leetcode;

/*
    414. Third Maximum Number
 */
public class LC_0414_ThirdMaximumNumber {
    public int thirdMax(int[] nums) {
        // 初始化要用长整型long的最小值，否则当数组中有INT_MIN存在时，程序就不知道该返回INT_MIN还是最大值first了
        long first = Long.MIN_VALUE, second = Long.MIN_VALUE, third = Long.MIN_VALUE;
        for (int num : nums) {
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second && num < first) {
                third = second;
                second = num;
            } else if (num > third && num < second) {
                third = num;
            }
        }
        long res = (third == Long.MIN_VALUE || third == second) ? first : third;
        return (int)res;
    }
}
