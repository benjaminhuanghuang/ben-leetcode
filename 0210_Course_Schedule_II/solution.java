package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
210. Course Schedule II

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.


 */
public class LC_0210_CourseSchedule_II {

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] indegree = new int[numCourses];
        // Step1: calculate in-degree
        for (int i = 0; i < prerequisites.length; i++) {
            indegree[prerequisites[i][0]]++;
        }

        // Step2: find nodes have 0 in-degree
        Queue<Integer> queue = new LinkedList<>();

        for (int i = 0; i < indegree.length; i++) {
            if (indegree[i] == 0) {
                queue.offer(i);
            }
        }

        // Step3: bfs
        List<Integer> res = new ArrayList<>();

        while (!queue.isEmpty()) {
            int pre = queue.poll();  // the course indegree is 0
            res.add(pre);

            for (int[] pair : prerequisites) {
                if (pair[1] == pre) {
                    indegree[pair[0]]--;
                    if (indegree[pair[0]] == 0) {
                        queue.offer(pair[0]);
                    }
                }
            }
        }

        int[] resArray = new int[numCourses];
        if (res.size() != numCourses)
            return new int[0];
        for(int i =0; i<numCourses;i++)
        {
            resArray[i]= res.get(i);
        }
        return resArray;
    }
}
