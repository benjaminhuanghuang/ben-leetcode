package cn.huang.leetcode;

/*
	849	Maximize Distance to Closest Person
 */
public class LC_0849_MaximizeDistancetoClosestPerson {
    public int maxDistToClosest(int[] seats) {
        int maxDistance = 0;
        int zero = 0;

        // 0 in the middle
        for (int i = 0; i < seats.length; i++) {
            if (seats[i] == 1) {
                zero = 0;
            } else {
                maxDistance = Math.max(maxDistance, (++zero + 1) / 2);
            }
        }

        // 0 at left
        zero = 0;
        for (int i = 0; i < seats.length; i++) {
            if (seats[i] == 1)
                break;
            zero++;
        }
        maxDistance = Math.max(maxDistance, zero);

        // 0 at right
        zero = 0;
        for (int i = seats.length - 1; i > 0; i--) {
            if (seats[i] == 1)
                break;
            zero++;
        }
        maxDistance = Math.max(maxDistance, zero);
        return maxDistance;
    }
}
