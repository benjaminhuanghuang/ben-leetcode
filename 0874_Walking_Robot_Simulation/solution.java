package cn.huang.leetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/*
	874	 Walking Robot Simulation


 */
public class LC_0874_WalkingRobotSimulation {
    public int robotSim(int[] commands, int[][] obstacles) {

        // north, west, south, east
        int[][] moves = new int[][]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        // face north
        int moveIndex = 0;
        int[] currPos = new int[]{0, 0};

        Map<Integer, Set<Integer>> map = new HashMap<>();
        int ans = 0;
        for (int[] ob : obstacles) {
            if (!map.containsKey(ob[0])) {
                map.put(ob[0], new HashSet<>());
            }
            map.get(ob[0]).add(ob[1]);
        }

        for (int i = 0; i < commands.length; i++) {
            if (commands[i] == -2) {
                // turn left 90 degrees
                moveIndex = (moveIndex + 1) % moves.length;
            } else if (commands[i] == -1) {
                // turn right 90 degrees
                moveIndex = (moveIndex - 1 + moves.length) % moves.length;
            } else if (1 <= commands[i] && commands[i] <= 9) {
                int[] next = new int[2];
                for (int j = 1; j <= commands[i]; j++) {
                    next[0] = currPos[0] + moves[moveIndex][0];
                    next[1] = currPos[1] + moves[moveIndex][1];
                    if (map.containsKey(next[0]) && map.get(next[0]).contains(next[1])) break;
                    currPos[0] = next[0];
                    currPos[1] = next[1];
                }
            }
            ans = Math.max(ans, currPos[0] * currPos[0] + currPos[1] * currPos[1]);
            //System.out.println(cur[0] + " " +  cur[1]);
        }

        return ans;

    }
}
