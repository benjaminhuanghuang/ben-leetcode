package cn.huang.leetcode;
/*
630. Course Schedule III

 There are n different online courses numbered from 1 to n. Each course has some duration(course length) t and closed
 on dth day. A course should be taken continuously for t days and must be finished before or on the dth day.
 You will start at the 1st day.

Given n online courses represented by pairs (t,d), your task is to find the maximal number of courses that can be taken.

Example:

Input: [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
Output: 3
Explanation:
There're totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day.
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day.
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.

Note:

    The integer 1 <= d, t, n <= 10,000.
    You can't take two courses simultaneously.


 */

import java.util.Arrays;
import java.util.PriorityQueue;

/*
每个课程有两个参数，第一个是课程的持续时间，第二个是课程的最晚结束日期，求最多能上多少门课。
 */
public class LC_0630_CourseSchedule_III {
    public int scheduleCourse(int[][] courses) {
        //按照课程截至日期排序
        Arrays.sort(courses, (a, b) -> {
            return a[1] - b[1];
        });
        //用最大优先级队列存储已经选择了的课程
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        int time = 0;
        for (int[] course : courses) {
            time += course[0];
            pq.add(course[0]);
            //如果当前考虑的课程超期了，就从已选择的课程中去掉课时最长的
            if (time > course[1]) {
                time -= pq.poll();
            }
        } //最终优先级队列中的课程数，就是能够选择的最多课程
        return pq.size();
    }
}
