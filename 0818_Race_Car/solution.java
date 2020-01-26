package cn.huang.leetcode;

/*
818. Race Car


Your car starts at position 0 and speed +1 on an infinite number line.  (Your car can go into negative positions.)

Your car drives automatically according to a sequence of instructions A (accelerate) and R (reverse).

When you get an instruction "A", your car does the following: position += speed, speed *= 2.

When you get an instruction "R", your car does the following: if your speed is positive then speed = -1 , otherwise speed = 1.  (Your position stays the same.)

For example, after commands "AAR", your car goes to positions 0->1->3->3, and your speed goes to 1->2->4->-1.

Now for some target position, say the length of the shortest sequence of instructions to get there.

Example 1:
Input:
target = 3
Output: 2
Explanation:
The shortest instruction sequence is "AA".
Your position goes from 0->1->3.

Example 2:
Input:
target = 6
Output: 5
Explanation:
The shortest instruction sequence is "AAARA".
Your position goes from 0->1->3->7->7->6.



Note:

    1 <= target <= 10000.


 */

/*
http://tashi711.xyz/programming/reports/leetcode/leetcode-818/
一开始车在无限长的的直线的坐标0处，速度为+1，有两种指令A（加速）和R（反向）。
当接收指令A时，位置加上速度的值，然后速度乘2，当接收指令R时，速度反向且绝对值变为1，位置不变。
现在给定终点位置，求问到达这个位置的最少指令数。
比如样例输入3，输出2（AA: 0->1->3）；输入6，输出5（AAARA: 0->1->3->7->7->6）
 */
public class LC_0818_RaceCar {

    public int racecar(int target) {
        int[] dp = new int[target + 1]; // dp[i]: min len for distance = i;
        fill(dp);
        solve(dp, target);
        return dp[target];
    }

    public int solve(int[] dp, int t) {
        if(dp[t] != 0 || t == 0) return dp[t];
        int k = find(t) - 1;
        int low = (int)Math.pow(2, k) - 1;
        int pos = 0, res = 10000;
        while(pos < k) {
            int back = (int)Math.pow(2, pos) - 1;
            res = Math.min(res, dp[low] + 2 + dp[back] + solve(dp, t - low + back));
            pos++;
        }
        k++;
        pos = 0;
        int high = (int)Math.pow(2, k) - 1;
        int res1 = dp[low] + 1 + 1 + solve(dp, high - t);
        dp[t] = Math.min(res, res1);
        return dp[t];
    }

    public int find(int t) {
        int ret = 0;
        while((int)Math.pow(2, ret) - 1 < t) ret++;
        return ret;
    }

    public void fill(int[] dp) {
        int count = 0;
        while((int)Math.pow(2, count) - 1 < dp.length) {
            dp[(int)Math.pow(2, count) - 1] = count;
            count++;
        }
    }
}
