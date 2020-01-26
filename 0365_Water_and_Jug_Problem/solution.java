package cn.huang.leetcode;
/*
365. Water and Jug Problem
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.

Operations allowed:

    Fill any of the jugs completely with water.
    Empty any of the jugs.
    Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.

Example 1: (From the famous "Die Hard" example)

Input: x = 3, y = 5, z = 4
Output: True

Example 2:

Input: x = 2, y = 6, z = 5
Output: False

 */
public class LC_0365_WaterandJugProblem {
    /*
    求最大公约数GCD（Greatest Common Divisor)。
     */
    public boolean canMeasureWater(int x, int y, int z) {
        if (z > x + y)
            return false;
        if (z == 0)
            return true;
        int res = gcd(x, y);
        return z % res == 0;
    }

    private int gcd(int x, int y) {

        return y == 0 ? x : gcd(y, x % y);
    }

    public int gcd2(int x, int y) {
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
}
