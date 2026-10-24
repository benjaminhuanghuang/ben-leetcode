/*
207. Course Schedule

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also 
have finished course 1. So it is impossible.

About Graph:
https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation/a/representing-graphs


Anaswer:
    http://blog.csdn.net/ljiabin/article/details/45846837
    https://discuss.leetcode.com/topic/16763/a-dfs-c-solution-308ms [Good]
*/
using System;
using System.Linq;
using System.Collections.Generic;

public class Solution207
{
    // 此问题等价于判断有向图中是否有环,
    // http://blog.csdn.net/ljiabin/article/details/45846837
    // 在一个有向图中，每次找到一个没有前驱节点的节点（也就是入度为0的节点），然后把它指向其他节点的边都去掉，
    // http://blog.welkinlan.com/2015/05/09/course-schedule-leetcode-java-dfs/
    public bool CanFinish(int numCourses, int[,] prerequisites)
    {
        if (numCourses <= 1)
            return true;

        // init and fill the adjacency list  //输入可能有重复的边，所以邻接表用HashSet存储。
        List<HashSet<int>> posts = new List<HashSet<int>>();
        for (int i = 0; i < numCourses; i++)
        {
            posts.Add(new HashSet<int>());
        }
        for (int i = 0; i < prerequisites.GetLength(0); i++)
        {
            posts[prerequisites[i, 1]].Add(prerequisites[i, 0]);
        }

        // count the pre-courses  
        int[] preNums = new int[numCourses];
        for (int i = 0; i < numCourses; i++)
        {
            HashSet<int> set = posts[i];
            foreach (var item in set)
            {
                preNums[item]++;
            }
        }

        // remove a non-pre course each time  
        for (int i = 0; i < numCourses; i++)
        {
            // find a non-pre course  
            int j;
            for (j = 0; j < numCourses; j++)
            {
                if (preNums[j] == 0) break;
            }

            // if not find a non-pre course  
            if (j == numCourses)
                return false;

            preNums[j] = -1;

            // decrease courses that post the course  
            HashSet<int> set = posts[j];
            foreach (int item in set)
            {
                preNums[item]--;
            }
        }

        return true;
    }

    public bool CanFinish_2(int numCourses, int[,] prerequisites)
    {
        List<int>[] depend = new List<int>[numCourses];
        for (int i = 0; i < numCourses; i++)
            depend[i] = new List<int>();
        for (int i = 0; i < prerequisites.GetLength(0); i++)
            depend[prerequisites[i, 0]].Add(prerequisites[i, 1]);

        bool[] history = new bool[numCourses];
        for (int i = 0; i < depend.Count(); i++)
            if (!dfsFinish(history, i, depend))
                return false;
        return true;
    }

    private bool dfsFinish(bool[] history, int courseNo, List<int>[] depend)
    {
        if (history[courseNo])
            return false;
        history[courseNo] = true;
        foreach (var d in depend[courseNo])
            if (!dfsFinish(history, d, depend))
                return false;
        history[courseNo] = false;
        return true;
    }
}