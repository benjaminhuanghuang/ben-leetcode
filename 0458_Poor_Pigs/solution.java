package cn.huang.leetcode;
/*
458. Poor Pigs

 */
public class LC_0458_PoorPigs {
    //http://www.cnblogs.com/grandyang/p/7664088.html
    //http://bookshadow.com/weblog/2016/11/08/leetcode-poor-pigs/
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if (buckets--==1){
            return 0;
        }
        int base=minutesToTest/minutesToDie+1;
        int count=0;
        while (buckets>0){
            buckets/=base;
            count++;
        }
        return count;
    }
}
