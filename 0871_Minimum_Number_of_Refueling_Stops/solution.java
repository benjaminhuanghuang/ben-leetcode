package cn.huang.leetcode;

import java.util.Collections;
import java.util.PriorityQueue;

/*
871. Minimum Number of Refueling Stops

A car travels from a starting position to a destination which is target miles east of the starting position.

Along the way, there are gas stations.  Each station[i] represents a gas station that is station[i][0] miles east of
the starting position, and has station[i][1] liters of gas.

The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it.  It uses 1 liter of
gas per 1 mile that it drives.

When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

What is the least number of refueling stops the car must make in order to reach its destination?  If it cannot reach
the destination, return -1.

Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there.  If the car reaches the
destination with 0 fuel left, it is still considered to have arrived.



Example 1:

Input: target = 1, startFuel = 1, stations = []
Output: 0
Explanation: We can reach the target without refueling.

Example 2:

Input: target = 100, startFuel = 1, stations = [[10,100]]
Output: -1
Explanation: We can't reach the target (or even the first gas station).

Example 3:

Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
Explanation:
We start with 10 liters of fuel.
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.



Note:

    1 <= target, startFuel, stations[i][1] <= 10^9
    0 <= stations.length <= 500
    0 < stations[0][0] < stations[1][0] < ... < stations[stations.length-1][0] < target


 */
public class LC_0871_MinimumNumberofRefuelingStops {
    /*
    dp[i][j]表示到达第i个加油站，经停j次时的最大油量

    状态转移方程：

    dp[i][j] = max(dp[i][j], dp[i - 1][j] - loc[i] + loc[i - 1])

    dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] - loc[i] + loc[i - 1] + fuel[i])

     */
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        return 0;
    }

    /*
    http://bookshadow.com/weblog/2018/07/15/leetcode-minimum-number-of-refueling-stops/
    优先队列pq（大顶堆）维护当前油量可以抵达的所有加油站。
    油量不足以到达下一个加油站时，从pq中弹出堆顶，并令计数器+1
     */
    public int minRefuelStops3(int target, int startFuel, int[][] stations) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int location = 0, stop = 0, fuel = startFuel;
        for (int[] st : stations) {
            if (fuel + location >= target) {
                return stop;
            }
            int sloc = st[0], sfuel = st[1];
            while (!pq.isEmpty() && fuel < sloc - location) {
                fuel += pq.poll();
                stop += 1;
            }
            if (fuel < sloc - location) {
                return -1;
            }
            fuel -= sloc - location;
            pq.add(sfuel);
            location = sloc;
        }
        while (!pq.isEmpty() && fuel < target - location) {
            fuel += pq.poll();
            stop += 1;
        }
        return fuel < target - location ? -1 : stop;
    }

    public int minRefuelStops2(int target, int startFuel, int[][] stations) {
        int furthest = startFuel;
        //优先队列pq（大顶堆）维护当前油量可以抵达的所有加油站。
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        int result = 0;
        int i = 0;
        for (result = 0; furthest < target; result++) {
            while (i < stations.length && furthest >= stations[i][0]) {
                maxHeap.offer(stations[i][1]);
                i++;
            }
            if (maxHeap.isEmpty()) {
                return -1;
            }
            furthest += maxHeap.poll();
        }
        return result;
    }
}
