package cn.huang.leetcode;

import java.util.HashSet;
import java.util.Set;

/*
    575. Distribute Candies
    Given an integer array with even length, where different numbers in this array represent different kinds of candies.
    Each number means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister.
    Return the maximum number of kinds of candies the sister could gain.
 */
public class LC_0575_DistributeCandies {
    /*
    一个数组，划分为元素个数相等的两份，使得其中一份中元素的值尽可能不相同。
    记录糖果种类，若糖果种类大于数组的一半，妹妹最多得到candies.size()/2种糖果,否则每种糖果都可以得到
     */
    public int distributeCandies(int[] candies) {
        Set<Integer> candyKinds = new HashSet<>();
        for (int candy : candies) {
            candyKinds.add(candy);
        }
        int kinds = candyKinds.size();
        int numTarget = candies.length / 2;
        return kinds >= numTarget ? numTarget : kinds;
    }
}
