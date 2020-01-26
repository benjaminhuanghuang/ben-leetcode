package cn.huang.leetcode;

/*
	840	 Magic Squares In Grid
 */
public class LC_0840_MagicSquaresInGrid {
    /*
        brute force
     */
    public int numMagicSquaresInside(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int res = 0;
        for (int i = 0; i + 2 < rows; i++) {
            for (int j = 0; j + 2 < cols; j++) {
                res += judge(i, j, grid);
            }
        }
        return res;
    }

    private int judge(int i, int j, int[][] grid) {
        if (grid[i + 1][j + 1] == 5)// center number is 5
        {

            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    if (grid[i + r][j + c] > 9 || grid[i + r][j + c] < 1)
                        return 0;
                }
            }
            // sum is 15
            if ((grid[i][j] + grid[i][j + 1] + grid[i][j + 2] == 15) &&
                    (grid[i + 1][j] + grid[i + 1][j + 1] + grid[i+1][j + 2] == 15) &&
                    (grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2] == 15) &&

                    (grid[i][j] + grid[i + 1][j] + grid[i + 2][j] == 15) &&
                    (grid[i][j+1] + grid[i + 1][j+1] + grid[i + 2][j+1] == 15) &&
                    (grid[i][j+2] + grid[i + 1][j+2] + grid[i + 2][j+2] == 15) &&

                    (grid[i][j] + grid[i+1][j+1] + grid[i + 2][j + 2] == 15) &&
                    (grid[i][j + 2] + grid[i+1][j+1] + grid[i + 2][j] == 15))
                return 1;

        }
        return 0;
    }
}
