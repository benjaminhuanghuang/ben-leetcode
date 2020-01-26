package cn.huang.leetcode;

import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

/*
895. Maximum Frequency Stack

 */
public class LC_0895_MaximumFrequencyStack {
    class FreqStack {

        PriorityQueue<int[]> pq;
        Map<Integer, Integer> map;
        int ct;

        public FreqStack() {
            pq = new PriorityQueue(new Comparator<int[]>() {
                public int compare(int[] a, int[] b) {
                    if (a[0] == b[0]) return b[1] - a[1];
                    return b[0] - a[0];
                }
            });
            map = new HashMap<>();
            ct = 0;
        }

        public void push(int x) {
            if (!map.containsKey(x)) map.put(x, 1);
            else map.put(x, map.get(x) + 1);
            pq.offer(new int[]{map.get(x), ct++, x});
        }

        public int pop() {
            int res = pq.poll()[2];
            map.put(res, map.get(res) - 1);
            return res;
        }
    }
}
