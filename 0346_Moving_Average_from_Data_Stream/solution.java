package cn.huang.leetcode;

import java.util.LinkedList;

/*
346.Moving Average from Data Stream

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
 */
public class LC_0346_MovingAveragefromDataStream {
    public class MovingAverage {
        LinkedList<Integer> queue;
        int size;
        double avg;

        /** Initialize your data structure here. */
        public MovingAverage(int size) {
            this.queue = new LinkedList<Integer>();
            this.size = size;
        }

        public double next(int val) {
            if(queue.size()<this.size){
                queue.offer(val);
                int sum=0;
                for(int i: queue){
                    sum+=i;
                }
                avg = (double)sum/queue.size();

                return avg;
            }else{
                int head = queue.poll();
                double minus = (double)head/this.size;
                queue.offer(val);
                double add = (double)val/this.size;
                avg = avg + add - minus;
                return avg;
            }
        }
    }
}
