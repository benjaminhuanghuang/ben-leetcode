package cn.huang.leetcode;
/*
822. Card Flipping Game

On a table are N cards, with a positive integer printed on the front and back of each card (possibly different).

We flip any number of cards, and after we choose one card.

If the number X on the back of the chosen card is not on the front of any card, then this number X is good.

What is the smallest number that is good?  If no number is good, output 0.

Here, fronts[i] and backs[i] represent the number on the front and back of card i.

A flip swaps the front and back numbers, so the value on the front is now on the back and vice versa.

Example:

Input: fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
Output: 2
Explanation: If we flip the second card, the fronts are [1,3,4,4,7] and the backs are [1,2,4,1,3].
We choose the second card, which has number 2 on the back, and it isn't on the front of any card, so 2 is good.



Note:

    1 <= fronts.length == backs.length <= 1000.
    1 <= fronts[i] <= 2000.
    1 <= backs[i] <= 2000.


 */

import java.util.HashSet;
import java.util.Set;

/*
首先是将卡片选取任意张进行翻转，再随机选取一张，如果这张卡片的的背面数字x没有在所有的正面数字中出现，那么这个数字x就是good的，
这个题目要求的是求取最小的满足good条件的数字。

找到最小的数字，没有任何一张牌的正反面都是这个数字，这个数字就是最小的好数。
 */
public class LC_0822_CardFlippingGame {
    public int flipgame(int[] fronts, int[] backs) {
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < fronts.length; i++) {
            if (fronts[i] == backs[i]) set.add(fronts[i]);
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < fronts.length; i++) {
            if (!set.contains(fronts[i]) && fronts[i] < res) {
                res = fronts[i];
            }
            if (!set.contains(backs[i]) && backs[i] < res) {
                res = backs[i];
            }
        }
        return res == Integer.MAX_VALUE ? 0 : res;
    }
}
