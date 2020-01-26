package cn.huang.leetcode;

/*
416. Partition Equal Subset Sum
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such
that the sum of elements in both subsets is equal.

Note:

    Each of the array element will not exceed 100.
    The array size will not exceed 200.

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.


 */
public class LC_0416_PartitionEqualSubsetSum {
    /*
   一个背包的题目，背包容量为数组中元素和的一半＋１，这样只要看是否有元素可以正好填满背包即可．但是每个元素只能用一次，
   所以在尝试放一个元素的时候还要避免他对尝试放其他位置时对自己的影响．所以在尝试放一个元素到背包的时候需要从容量最大的位置开始，
   如果（当前位置－当前元素大小）位置可以通过放置之前的元素达到，则当前位置也可以通过放置当前元素正好达到这个位置．
   状态转移方程为：dp[i] = dp[i] || dp[i - nums[k]];
    https://blog.csdn.net/MebiuW/article/details/52765840
     */

    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 == 1)
            return false;

        sum /= 2;
        int n = nums.length; // dp[i][j] 表示 如果我们取前i个数字，且背包容量为j的情况下，最多能放入多少东西
        int dp[][] = new int[n][sum + 1]; // dp[0][0] 为初始状态，表示，没有任何没有东西没有体积，其余部分初始化
        for (int i = nums[0]; i <= sum; i++) {
            dp[0][i] = nums[0];
        }
        //遍历n个数字，即视为n个产品
        for (int i = 1; i < n; i++) { //加入了这种物品后更新状态
            for (int j = nums[i]; j <= sum; j++) {
                dp[i][j]=Math.max(dp[i-1][j], dp[i-1][j-nums[i]]+nums[i]);
            }
        }
        //放满了才能表示正好1/2
        return dp[n - 1][sum] == sum;
    }
}
