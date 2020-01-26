package cn.huang.leetcode;
/*
810. Chalkboard XOR Game

We are given non-negative integers nums[i] which are written on a chalkboard.  Alice and Bob take turns erasing exactly one number from the chalkboard, with Alice starting first.  If erasing a number causes the bitwise XOR of all the elements of the chalkboard to become 0, then that player loses.  (Also, we'll say the bitwise XOR of one element is that element itself, and the bitwise XOR of no elements is 0.)

Also, if any player starts their turn with the bitwise XOR of all the elements of the chalkboard equal to 0, then that player wins.

Return True if and only if Alice wins the game, assuming both players play optimally.

Example:
Input: nums = [1, 1, 2]
Output: false
Explanation:
Alice has two choices: erase 1 or erase 2.
If she erases 1, the nums array becomes [1, 2]. The bitwise XOR of all the elements of the chalkboard is 1 XOR 2 = 3. Now Bob can remove any element he wants, because Alice will be the one to erase the last element and she will lose.
If Alice erases 2 first, now nums becomes [1, 1]. The bitwise XOR of all the elements of the chalkboard is 1 XOR 1 = 0. Alice will lose.

Notes:

    1 <= N <= 1000.
    0 <= nums[i] <= 2^16.

 */

/*
给定N个数，A和B轮流各取一个数，谁取之后剩下的所有数异或为0就输，A先取，如果一开始所有数异或为0也算A赢。
两个人同样聪明，求问A能不能赢。N范围为1到1000，数的范围0到2的16次方。
比如样例路线为 [1, 1, 2]，则A输。
解题思路

一开始想是一个博弈论的模型，不过建博弈树的复杂度貌似有点高。
其实仔细想想会发现如果当前有至少两种数剩下时，一定可以取到异或不为0的情况。
因此一定会取到最后一个数，直接判断数量的奇偶就好了，奇数个数一定是A输。
即使不用取到最后一个数，必输的状态也一定是奇数个相同的数。
细节处理

注意如果一开始所有数异或为0也算A赢，无论奇偶。
复杂度分析

时间复杂度为 O(N)
，主要是要扫一遍看看是不是一开始就是异或为0。
空间复杂度为 O(1)，不考虑输入的空间的话。
 */
public class LC_0810_ChalkboardXORGame {
    public boolean xorGame(int[] nums) {
        int n = (int)nums.length;
        int s = 0;
        for (int i = 0; i < n; ++i) {
            s ^= nums[i];
        }
        return s == 0 || n % 2 == 0;
    }
}
