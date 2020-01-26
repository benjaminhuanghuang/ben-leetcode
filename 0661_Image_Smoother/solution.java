package cn.huang.leetcode;

/*
    661. Image Smoother
 */
public class LC_0661_ImageSmoother {
    public int[][] imageSmoother(int[][] M) {
        if (M == null) return null;
        int rows = M.length;
        if (rows == 0) return new int[0][];
        int cols = M[0].length;

        int result[][] = new int[rows][cols];

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int count = 0;
                int sum = 0;
                for (int rInc : new int[]{-1, 0, 1}) {
                    for (int cInc : new int[]{-1, 0, 1}) {
                        if (isValid(row + rInc, col + cInc, rows, cols)) {
                            count++;
                            sum += M[row + rInc][col + cInc];
                        }
                    }
                }
                result[row][col] = sum / count;
            }
        }

        return result;
    }

    private boolean isValid(int x, int y, int rows, int cols) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }
    public int[][] imageSmoother_better(int[][] M) {
        if (M == null || M.length < 1 || M[0].length < 1) return M;
        int m = M.length, n = M[0].length;
        int[][] res = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int temp = 0, cnt = 0;
                for (int k = Math.max(0, i - 1); k <= Math.min(i + 1, m - 1); k++) {
                    for (int l = Math.max(0, j - 1); l <= Math.min(j + 1, n - 1); l++) {
                        temp += M[k][l];
                        cnt++;
                    }
                }
                res[i][j] = temp / cnt;
            }
        }
        return res;
    }
}
