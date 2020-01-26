/*
210. Course Schedule II

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses 
you should take to finish all courses.

There may be multiple correct orders, you just need to return "one" of them. If it is impossible to 
finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the 
correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 
and 2. 
Both courses 1 and 2 should be taken after you finished course 0. 
So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

*/
using System;
using System.Collections.Generic;

public class Solution210 {
    bool[] visited;
    public int[] FindOrder(int numCourses, int[,] prerequisites)
    {
        visited = new bool[numCourses];
        var res = new List<int>();

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                var returns = FindOrderDFS(numCourses, prerequisites, i, new List<int>());
                if(returns == null) 
                    return new int[]{};
                res.AddRange(returns);
            }
        }

        res.Reverse();
        return res.ToArray();
    }

    private int[] FindOrderDFS(int numCourses, int[,] prerequisites, int start, List<int> parents)
    {
        var res = new List<int>();

        int rows = prerequisites.GetLength(0);
        int columns = prerequisites.GetLength(1);

        for (int i = 0; i < rows; i++)
        {
            if (prerequisites[i, 1] == start && !visited[prerequisites[i, 0]])
            {
                if (parents.Contains(prerequisites[i, 0]))
                {
                    return null;
                }
                parents.Add(start);
                var rest = FindOrderDFS(numCourses, prerequisites, prerequisites[i, 0], parents);

                if(rest == null)
                {
                    return null;
                }
                res.AddRange(rest);
            }
        }

        res.Add(start);
        visited[start] = true;

        return res.ToArray();
    }
}