package cn.huang.leetcode;

import java.util.Arrays;

/*
853. Car Fleet

N cars are going to the same destination along a one lane road.  The destination is target miles away.

Each car i has a constant speed speed[i] (in miles per hour), and initial position position[i] miles towards the target along the road.

A car can never pass another car ahead of it, but it can catch up to it, and drive bumper to bumper at the same speed.

The distance between these two cars is ignored - they are assumed to have the same position.

A car fleet is some non-empty set of cars driving at the same position and same speed.  Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.


How many car fleets will arrive at the destination?



Example 1:

Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
Output: 3
Explanation:
The cars starting at 10 and 8 become a fleet, meeting each other at 12.
The car starting at 0 doesn't catch up to any other car, so it is a fleet by itself.
The cars starting at 5 and 3 become a fleet, meeting each other at 6.
Note that no other cars meet these fleets before the destination, so the answer is 3.

 */
public class LC_0853_CarFleet
{
    /*
    https://www.cnblogs.com/lightwindy/p/9795809.html
     */
    public int carFleet(int target, int[] position, int[] speed) {
        int N = position.length;
        int res = 0;
        //建立位置-时间的N行2列的二维数组
        double[][] cars = new double[N][2];
        for (int i = 0; i < N; i++) {
            cars[i] = new double[]{position[i], (double) (target - position[i]) / speed[i]};
        }
        Arrays.sort(cars, (a, b) -> Double.compare(a[0], b[0]));
        double cur = 0;

        //从后往前比较
        for (int i = N - 1; i >= 0; i--) {
            if (cars[i][1] > cur) {
                cur = cars[i][1];
                res++;
            }
        }
        return res;
    }
}
