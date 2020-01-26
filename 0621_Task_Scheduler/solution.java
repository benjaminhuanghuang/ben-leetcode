package cn.huang.leetcode;

import java.util.Arrays;

/*
621. Task Scheduler
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters
represent different tasks. Tasks could be done without original order. Each task could be done in one interval.
For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n
intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.



Example:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.



Note:

    The number of tasks is in the range [1, 10000].
    The integer n is in the range [0, 100].


 */
public class LC_0621_TaskScheduler {
    public int leastInterval(char[] tasks, int n) {
        int[] count = new int[26];
        for (char task : tasks) {
            count[task - 'A']++;
        }
        Arrays.sort(count);

        int intervals = 0;
        while (count[25] > 0) {
            for (int i = 0; i <= n; i++) {
                intervals++;
                if (i > 25) {
                    continue;
                }
                int index = 25 - i;
                if (count[index] > 0) {
                    count[index]--;
                }
                if (count[index] == 0 && count[25] == 0) {
                    break;
                }
            }
            Arrays.sort(count);
        }
        return intervals;
    }
}
