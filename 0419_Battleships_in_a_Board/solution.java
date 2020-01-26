package cn.huang.leetcode;

/*
419. Battleships in a Board

 */
public class LC_0419_BattleshipsinaBoard {
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    public int countBattleships(char[][] board) {
        int n = board.length;
        if (n == 0) {
            return 0;
        }
        int m = board[0].length;
        int count = 0;

        boolean[][] visited = new boolean[n][m];
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (board[i][j] == 'X' && !visited[i][j]) {
                    DFS(i, j, n, m, board, visited);
                    count ++;
                }
            }
        }
        return count;
    }

    void DFS(int x, int y, int n, int m, char[][] board, boolean[][] visited) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i ++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && yy >= 0 && xx < n && yy < m && board[xx][yy] == 'X' && !visited[xx][yy]) {
                DFS(xx, yy, n, m, board, visited);
            }
        }
    }
}
