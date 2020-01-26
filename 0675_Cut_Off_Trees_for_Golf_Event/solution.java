package cn.huang.leetcode;

import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

/*
675. Cut Off Trees for Golf Event

 You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:

    0 represents the obstacle can't be reached.
    1 represents the ground can be walked through.
    The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree's height.

You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree with lowest height first. And after cutting, the original place has the tree will become a grass (value 1).

You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees. If you can't cut off all the trees, output -1 in that situation.

You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.

Example 1:

Input:
[
 [1,2,3],
 [0,0,4],
 [7,6,5]
]
Output: 6

Example 2:

Input:
[
 [1,2,3],
 [0,0,0],
 [7,6,5]
]
Output: -1

Example 3:

Input:
[
 [2,3,4],
 [0,0,5],
 [8,7,6]
]
Output: 6
Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.

 */

/*
    matrix代表高尔夫球场. 0表示石头, 没法移动. 1表示空地可以走动. 大于1的都表示树, 并且也都可以走动. 然后需要砍树，只能按照顺序来砍,
    砍完之后格子里数就变成1. 问从左上角开始, 最少需要走多少步才能把所有的树都按照顺序砍完. (树的高度不会有重复)
 */
public class LC_0675_CutOffTreesforGolfEvent {
    private static int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public int cutOffTree(List<List<Integer>> forest) {
        if (forest.get(0).get(0) == 0) return -1;
        final int m = forest.size();
        final int n = forest.get(0).size();
        final PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest.get(i).get(j) > 1) {
                    minHeap.offer(new int[]{forest.get(i).get(j), i, j});
                }
            }
        }
        int sum = 0;
        int row = 0, col = 0;
        while (!minHeap.isEmpty()) {
            final int[] curr = minHeap.poll();
            int length = bfs(curr[0], row, col, forest);
            if (length == -1) return -1;
            else sum += length;
            row = curr[1];
            col = curr[2];
        }
        return sum;
    }

    private int bfs(final int target, final int row, final int col, final List<List<Integer>> forest) {
        final int m = forest.size();
        final int n = forest.get(0).size();
        final boolean[][] visited = new boolean[m][n];
        final Queue<Integer> queue = new LinkedList<>();
        queue.offer(row * n + col);
        visited[row][col] = true;
        int currLen = 0;
        while (!queue.isEmpty()) {
            final int size = queue.size();
            for (int i = 0; i < size; i++) {
                int front = queue.poll();
                int x = front / n;
                int y = front % n;
                if (forest.get(x).get(y) == target) return currLen;
                for (final int[] d : dir) {
                    final int nextX = x + d[0];
                    final int nextY = y + d[1];
                    if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n
                            && !visited[nextX][nextY] && forest.get(nextX).get(nextY) != 0) {
                        queue.offer(nextX * n + nextY);
                        visited[nextX][nextY] = true;
                    }
                }
            }
            currLen++;
        }
        return -1;
    }
}
