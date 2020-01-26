package cn.huang.leetcode;

import java.util.*;

/*
815. Bus Routes

 We have a list of bus routes. Each routes[i] is a bus route that the i-th bus repeats forever. For example if routes[0] = [1, 5, 7], this means that the first bus (0-th indexed) travels in the sequence 1->5->7->1->5->7->1->... forever.

We start at bus stop S (initially not on a bus), and we want to go to bus stop T. Travelling by buses only, what is the least number of buses we must take to reach our destination? Return -1 if it is not possible.

Example:
Input:
routes = [[1, 2, 7], [3, 6, 7]]
S = 1
T = 6
Output: 2
Explanation:
The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.

Note:

    1 <= routes.length <= 500.
    1 <= routes[i].length <= 500.
    0 <= routes[i][j] < 10 ^ 6.


 */
public class LC_0815_BusRoutes {
    /*
    https://www.youtube.com/watch?v=vEcm5farBls
     */
    public int numBusesToDestination(int[][] routes, int S, int T) {
        if (S == T) return 0;

        //pre-processing: save <stop, List<buses>> for BFS
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < routes.length; i++) {
            for (int stop : routes[i]) {
                if (!map.containsKey(stop)) map.put(stop, new ArrayList<>());
                map.get(stop).add(i);
            }
        }

        if (!map.containsKey(S) || !map.containsKey(T)) return -1;

        Set<Integer> visited = new HashSet<>(); //to store visited routes
        Deque<Integer> queue = new ArrayDeque<>();
        queue.offer(S);

        int transitions = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            transitions++;
            for (int i = 0; i < size; i++) {
                int curStop = queue.poll();
                List<Integer> buses = map.get(curStop);
                for (int bus : buses) {
                    if (visited.contains(bus)) continue;
                    visited.add(bus);
                    for (int stop : routes[bus]) {
                        if (stop == T) return transitions;
                        else queue.offer(stop);
                    }
                }
            }
        }

        return -1;
    }
}
