package cn.huang.leetcode;

import java.util.LinkedList;
import java.util.Queue;

/*
933. Number of Recent Calls

Write a class RecentCounter to moves recent requests.

It has only one method: ping(int t), where t represents some time in milliseconds.

Return the number of pings that have been made from 3000 milliseconds ago until now.

Any ping with time in [t - 3000, t] will moves, including the current ping.

It is guaranteed that every call to ping uses a strictly larger value of t than before.



Example 1:

Input: inputs = ["RecentCounter","ping","ping","ping","ping"], inputs = [[],[1],[100],[3001],[3002]]
Output: [null,1,2,3,3]

保留ping 中 与最新记录差小于3000的记录。
 */
public class LC_0933_NumberofRecentCalls {
    class RecentCounter {
        Queue<Integer> queue ;
        public RecentCounter() {
            queue= new LinkedList<>();
        }

        public int ping(int t) {
            while(!queue.isEmpty() && (t - queue.peek())>3000)
                queue.poll();
            queue.add(t);
            return queue.size();
        }
    }
}
