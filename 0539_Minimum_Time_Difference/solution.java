package cn.huang.leetcode;

import java.util.Collections;
import java.util.List;

/*
539. Minimum Time Difference

Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.

Example 1:

Input: ["23:59","00:00"]
Output: 1

Note:

    The number of time points in the given list is at least 2 and won't exceed 20000.
    The input time is legal and ranges from 00:00 to 23:59.

 */
public class LC_0539_MinimumTimeDifference {
    public int findMinDifference(List<String> timePoints) {
        Collections.sort(timePoints);
        int minDiff = Integer.MAX_VALUE;
        for (int i = 1; i < timePoints.size(); i++) {
            minDiff = Math.min(minDiff, calcDiff(timePoints.get(i - 1), timePoints.get(i)));
        }
        minDiff = Math.min(minDiff, calcDiff(timePoints.get(0), timePoints.get(timePoints.size() - 1)));
        return minDiff;
    }

    private int calcDiff(String a, String b) {
        int aH = Integer.parseInt(a.substring(0, 2)),
                bH = Integer.parseInt(b.substring(0, 2)),
                aM = Integer.parseInt(a.substring(3, 5)),
                bM = Integer.parseInt(b.substring(3, 5));

        int diff = 60 * bH + bM - 60 * aH - aM;
        return Math.min(diff, 1440 - diff);   // for case ["23:59","00:00"]
    }
}
