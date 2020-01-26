package cn.huang.leetcode;

import java.util.LinkedList;
import java.util.Queue;

/*
934. Shortest Bridge

In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)


 */
public class LC_0934_ShortestBridge {
    /*
    首先这个题目规定只有两个岛，这非常重要， 如果有多个岛， 题目就会变得比较复杂。 比如我就读错题目了
    判断一个岛屿很简单，可以用bfs，也可以用dfs， 相对而言dfs简洁一点，因为不需要一个额外的queue
    判断一个岛屿和另外一个岛屿的距离，可以用bfs，每次向周围的节点扩散一圈（就是每个节点都向外扩散一次）， 直到遇到另外一个岛屿就好
    这里对大数据一个重点的优化是及时设置状态，避免节点被重复加入。
     */
    public int shortestBridge(int[][] A) {
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < A.length; ++i) {
            for (int j = 0; j < A[0].length; ++j) {
                if (A[i][j] == 1) {  // it is island
                    dfs(A, i, j, queue);
                    break;
                }
            }
            if (queue.size() > 0) break;
        }

        int step = 0;
        while (queue.size() > 0) {
            int size = queue.size();
            for (int k = 0; k < size; ++k) {
                int[] pos = queue.poll();
                int i = pos[0], j = pos[1];
                if (A[i][j] == 1) return step - 1;

                add(queue, A, i + 1, j);
                add(queue, A, i - 1, j);
                add(queue, A, i, j + 1);
                add(queue, A, i, j - 1);
            }

            step++;
        }
        return -1;
    }

    public void add(Queue<int[]> queue, int[][] a, int i, int j) {
        if (i < 0 || i >= a.length || j < 0 || j >= a[0].length)
            return;
        if (a[i][j] == 0 || a[i][j] == 1) {
            if (a[i][j] == 0) {  // key thing to update here rather than after queue.poll()
                a[i][j] = 2;
            }
            queue.add(new int[]{i, j});
        }
    }
    // distance
    public void dfs(int[][] a, int i, int j, Queue<int[]> queue) {
        if (i < 0 || i >= a.length || j < 0 || j >= a[0].length)
            return;
        if (a[i][j] != 1)
            return;

        a[i][j] = 2;
        queue.add(new int[]{i, j});

        dfs(a, i + 1, j, queue);
        dfs(a, i - 1, j, queue);
        dfs(a, i, j + 1, queue);
        dfs(a, i, j - 1, queue);
    }
}
