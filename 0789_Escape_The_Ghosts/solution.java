package cn.huang.leetcode;
/*
789. Escape The Ghosts

You are playing a simplified Pacman game. You start at the point (0, 0), and your destination is (target[0], target[1]).
There are several ghosts on the map, the i-th ghost starts at (ghosts[i][0], ghosts[i][1]).

Each turn, you and all ghosts simultaneously *may* move in one of 4 cardinal directions: north, east, west, or south,
going from the previous point to a new point 1 unit of distance away.

You escape if and only if you can reach the target before any ghost reaches you (for any given moves the ghosts may take.)
If you reach any square (including the target) at the same time as a ghost, it doesn't moves as an escape.

Return True if and only if it is possible to escape.
 */
public class LC_0789_EscapeTheGhosts {
    /*
    如果所有的幽灵都无法在你之前到达target，那么你可以逃脱。只要比较曼哈顿距离即可。
    曼哈顿距离——两点在南北方向上的距离加上在东西方向上的距离，即d（i，j）=|xi-xj|+|yi-yj|。
     */
    public boolean escapeGhosts(int[][] ghosts, int[] target) {
        int steps = Math.abs(target[0]) + Math.abs(target[1]);
        for (int[] g : ghosts)
            if (Math.abs(g[0] - target[0]) + Math.abs(g[1] - target[1]) <= steps)
                return false;
        return true;
    }
}
