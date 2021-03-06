package cn.huang.leetcode;

/*
803. Bricks Falling When Hit

We have a grid of 1s and 0s; the 1s in a cell represent bricks.  A brick will not drop if and only if it is directly
connected to the top of the grid, or at least one of its (4-way) adjacent bricks will not drop.

We will do some erasures sequentially. Each time we want to do the erasure at the location (i, j), the brick
(if it exists) on that location will disappear, and then some other bricks may drop because of that erasure.

Return an array representing the number of bricks that will drop after each erasure in sequence.

Example 1:
Input:
grid = [[1,0,0,0],[1,1,1,0]]
hits = [[1,0]]
Output: [2]
Explanation:
If we erase the brick at (1, 0), the brick at (1, 1) and (1, 2) will drop. So we should return 2.

Example 2:
Input:
grid = [[1,0,0,0],[1,1,0,0]]
hits = [[1,1],[1,0]]
Output: [0,0]
Explanation:
When we erase the brick at (1, 0), the brick at (1, 1) has already disappeared due to the last move. So each erasure will cause no bricks dropping.  Note that the erased brick (1, 0) will not be counted as a dropped brick.



Note:

    The number of rows and columns in the grid will be in the range [1, 200].
    The number of erasures will not exceed the area of the grid.
    It is guaranteed that each erasure will be different from any other erasure, and located inside the grid.
    An erasure may refer to a location with no brick - if it does, no bricks drop.


 */
public class LC_0803_BricksFallingWhenHit {
    /*
    https://blog.csdn.net/tiefanhe/article/details/79957467
    题目大意： 在矩阵中，1表示 有brick， 0 表示没有brick。 当brick 直接和top （也就是第一行上的brick） 能够相连，或者通过他四周4个方向上的brick 能够和 top相连，那么该brick 就不会下落。
    题目中，输入一组坐标，来表示依次删除坐标上的brick （有可能没有brick）。 求，会有多少个brick 下落。
    思路：
    1） 根据删除的brick 所在位置以及特性分为以下几种情况
    #A, 当删除index处为0， 则drop为0.
    #B, 当删除index处为1：
    #B.1 当删除位置的brick 不和top相连， 则drop为0.
    #B.2 当删除位置的brick 和 top 相连
    #B.2.1 BFS 该brick四周的各个bricks，如果各个bricks 能够通过其他bricks 到达 top，则该子brick 不会drop
    #B.2.2 否则会drop。

     */
    public int[] hitBricks(int[][] grid, int[][] hits) {
        if (hits.length == 0 || hits[0].length == 0) return null;
        //删除 hits中所有的bricks， 进而为下面找出所有不通过 hits 就能够到达top 的bricks 做准备。
        //在remove中， 如果hit[i][j]在grid中为0， 同样会--，则为-1.
        removeHitBrick(grid, hits);
        //标记所有剩余的bricks，如果该bricks 能够到达top，则设其为2.
        markRemainBricks(grid);
        //找出所有可能会drop的bricks
        return searchFallingBrick(grid, hits);
    }

    private void removeHitBrick(int[][] grid, int[][] hits) {
        for (int i = 0; i < hits.length; i++) {
            //如果 hits处，没有brick 则设为-1，如果有brick 则清空为0
            grid[hits[i][0]][hits[i][1]] = grid[hits[i][0]][hits[i][1]] - 1;
        }
    }

    private void markRemainBricks(int[][] grid) {
        for (int i = 0; i < grid[0].length; i++) {
            //这里，只从第0行出发，dfs，找出所有能够到达top 的brick， 并将其设为2.
            dfs(grid, 0, i);
        }
    }

    private int[] searchFallingBrick(int[][] grid, int[][] hits) {
        int[] result = new int[hits.length];
        //从后向前遍历hits。
        for (int i = hits.length - 1; i >= 0; i--) {
            //如果grid 初为0，则表明hit处有brick。
            if (grid[hits[i][0]][hits[i][1]] == 0) {
                grid[hits[i][0]][hits[i][1]] = 1;
                //如果hit处的brick能够到达top
                if (isConnectToTop(grid, hits[i][0], hits[i][1])) {
                    //找出 删掉该brick 后， 有多少 其他的bricks 会掉落。
                    //因为从top出发能够到达的bricks 已经都设为2了，所以这些brick 不会再dfs中再次找到。
                    //同样的，当从hit处的brick出发，找到被影响的brick后，设这些brick为2，以便于后面的hit 不会重复计数。
                    result[i] = dfs(grid, hits[i][0], hits[i][1]) - 1;
                } else {
                    //如果hit处的brick 无法到达top，则不会有任何brick 掉落。
                    result[i] = 0;
                }
            }
        }
        return result;
    }

    //判断从i,j出发，能否到达 top.
    private boolean isConnectToTop(int[][] grid, int i, int j) {
        if (i == 0) return true;

        if (i - 1 >= 0 && grid[i - 1][j] == 2) {
            return true;
        }
        if (i + 1 < grid.length && grid[i + 1][j] == 2) {
            return true;
        }
        if (j - 1 >= 0 && grid[i][j - 1] == 2) {
            return true;
        }
        if (j + 1 < grid[0].length && grid[i][j + 1] == 2) {
            return true;
        }
        return false;
    }

    private int dfs(int[][] data, int row, int column) {
        int arrayRow = data.length;
        int arrayLine = data[0].length;
        int effectBricks = 0;
        if (row < 0 || row >= arrayRow) return effectBricks;
        if (column < 0 || column >= arrayLine) return effectBricks;
        if (data[row][column] == 1) {
            data[row][column] = 2;
            effectBricks = 1;
            effectBricks += dfs(data, row + 1, column);
            effectBricks += dfs(data, row - 1, column);
            effectBricks += dfs(data, row, column + 1);
            effectBricks += dfs(data, row, column - 1);
        }
        return effectBricks;
    }
}
