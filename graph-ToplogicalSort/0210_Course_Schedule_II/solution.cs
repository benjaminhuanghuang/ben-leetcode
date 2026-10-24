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