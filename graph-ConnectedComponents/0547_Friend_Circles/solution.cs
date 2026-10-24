public class Solution547
{
    /*
        找到图中连通分量的个数
     */
    public int FindCircleNum(int[,] M)
    {
        if (M == null)
            return 0;
        int studentCount = M.GetLength(0);
        if (studentCount < 1)
            return 0;

        bool[] visited = new bool[studentCount];
        int cycle = 0;
        for (int i = 0; i < studentCount; i++)
        {
            if (!visited[i])
            {
                cycle++;
                visited[i] = true;
                dfs(M, visited, i);
            }
        }
        return cycle;
    }
    private void dfs(int[,] M, bool[] visited, int i)
    {
        for (int j = 0; j < M.GetLength(0); j++)
        {
            if (!visited[j] && M[i,j] == 1)
            {
                visited[j] = true;
                dfs(M, visited, j);
            }
        }
    }
}