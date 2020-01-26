package cn.huang.leetcode;

/*
743. Network Delay Time
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node,
v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.
 */
public class LC_0743_NetworkDelayTime {
    public int networkDelayTime(int[][] times, int N, int K) {
        int[] dist = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[K] = 0;   // dist from node K to node K

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < times.length; j++) {
                int source = times[j][0];
                int target = times[j][1];
                int time = times[j][2];
                if(dist[source] != Integer.MAX_VALUE && dist[target]> dist[source] + time)
                    dist[target] = dist[source] + time;
            }
        }
        int max_time = 0;
        for (int i = 1; i <= N; i++) {
            max_time = Math.max(max_time, dist[i]);
        }

        return max_time == Integer.MAX_VALUE ? -1 : max_time;
    }
}
