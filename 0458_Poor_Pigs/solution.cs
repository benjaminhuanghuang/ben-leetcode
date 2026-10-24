using System;

public class Solution458 {
    //http://bookshadow.com/weblog/2016/11/08/leetcode-poor-pigs/
    public int PoorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return (int)(Math.Ceiling(Math.Log(buckets, 1 + minutesToTest / minutesToDie)));
    }
}