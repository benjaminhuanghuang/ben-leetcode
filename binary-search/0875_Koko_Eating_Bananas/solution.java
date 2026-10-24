package cn.huang.leetcode;

/*
875. Koko Eating Bananas

Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has piles[i] bananas.
The guards have gone and will come back in H hours.

Koko can decide her bananas-per-hour eating speed of K.  Each hour, she chooses some pile of bananas,
 and eats K bananas from that pile.  If the pile has less than K bananas, she eats all of them instead, \
 and won't eat any more bananas during this hour.

Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.

Return the minimum integer K such that she can eat all the bananas within H hours.



Example 1:

Input: piles = [3,6,7,11], H = 8
Output: 4

Example 2:

Input: piles = [30,11,23,4,20], H = 5
Output: 30

Example 3:

Input: piles = [30,11,23,4,20], H = 6
Output: 23



Note:

    1 <= piles.length <= 10^4
    piles.length <= H <= 10^9
    1 <= piles[i] <= 10^9


 */
public class LC_0875_KokoEatingBananas {
    /*
    吃香蕉的深度最慢是1，最快是max(piles) ，那么我们求的解，一定在这个两个值之间，所以现在就可以用二分法查找，
    search for the smallest k [1, max_pile_height] such that eating time h <= H.
     */
    public int minEatingSpeed(int[] piles, int H) {
        int minSpeed = 1;
        int maxSpeed = getMaxValue(piles);
        while (minSpeed < maxSpeed) {
            int speed = (maxSpeed - minSpeed) / 2 + minSpeed;
            int hour = 0;
            for (int p : piles)
                hour += (p + speed - 1) / speed;  //hour += math.ceil(pile / speed)
            if (hour <= H)
                maxSpeed = speed;
            else
                minSpeed = speed + 1;
        }
        return minSpeed;
    }

    private int getMaxValue(int[] numbers) {
        int maxValue = numbers[0];
        for (int i = 1; i < numbers.length; i++) {
            if (numbers[i] > maxValue) {
                maxValue = numbers[i];
            }
        }
        return maxValue;
    }
}
