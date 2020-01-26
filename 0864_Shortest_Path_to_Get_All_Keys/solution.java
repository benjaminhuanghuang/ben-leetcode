package cn.huang.leetcode;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

/*
864. Shortest Path to Get All Keys

We are given a 2-dimensional grid. "." is an empty cell, "#" is a wall, "@" is the starting point, ("a", "b", ...) are keys, and ("A", "B", ...) are locks.

We start at the starting point, and one move consists of walking one space in one of the 4 cardinal directions.  We cannot walk outside the grid, or walk into a wall.  If we walk over a key, we pick it up.  We can't walk over a lock unless we have the corresponding key.

For some 1 <= K <= 6, there is exactly one lowercase and one uppercase letter of the first K letters of the English alphabet in the grid.  This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

Return the lowest number of moves to acquire all keys.  If it's impossible, return -1.



Example 1:

Input: ["@.a.#","###.#","b.A.B"]
Output: 8

Example 2:

Input: ["@..aA","..B#.","....b"]
Output: 6



Note:

    1 <= grid.length <= 30
    1 <= grid[0].length <= 30
    grid[i][j] contains only '.', '#', '@', 'a'-'f' and 'A'-'F'
    The number of keys is in [1, 6].  Each key has a different letter and opens exactly one lock.


 */
public class LC_0864_ShortestPathtoGetAllKeys
{
    public int shortestPathAllKeys(String[] grid) {
        int m = grid.length, n = grid[0].length();
        char[][] ch = new char[m][n];
        Set<String> set = new HashSet<>();
        Queue<int[]> queue = new LinkedList<>();
        int end = 1;

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                ch[i][j] = grid[i].charAt(j);
                if(Character.isLowerCase(ch[i][j])) {
                    end |= (1 << (ch[i][j] - 'a'));
                }
                if(ch[i][j] == '@') {
                    queue.offer(new int[]{i * n + j, 0});
                    set.add(i * n + j + " " + 0);
                }
            }
        }

        int[][] delta = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int res = 0;
        while(!queue.isEmpty()) {
            int size = queue.size();
            res++;
            for(int i = 0; i<size; i++) {
                int[] cell = queue.poll();
                int x = cell[0] / n;
                int y = cell[0] % n;
                for(int j = 0; j<4; j++) {
                    int row = x + delta[j][0];
                    int col = y + delta[j][1];
                    int num = row * n + col;
                    if(row >= 0 && col >= 0 && row < m && col < n && ch[row][col] != '#') {
                        int mask = cell[1];
                        if(Character.isLowerCase(ch[row][col])) {
                            mask |= (1 << (ch[row][col] - 'a'));
                            if(mask == end) return res;
                        }
                        if(Character.isUpperCase(ch[row][col])) {
                            if((cell[1] & (1 << (ch[row][col] - 'A'))) == 0){
                                continue;
                            }
                        }
                        if(set.add(num + " " + mask)) {
                            queue.offer(new int[]{num, mask});
                        }
                    }
                }
            }
        }

        return -1;
    }
}
