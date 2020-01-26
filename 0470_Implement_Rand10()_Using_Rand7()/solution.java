package cn.huang.leetcode;
/*
470. Implement Rand10() Using Rand7()

 */
public class LC_0470_ImplementRand10UsingRand7 {
    class SolBase {
        public int rand7() {
            return 0;
        }
    }
 /*
 用randN生成randM，其中N<M的基本思想是：

首先找到一个能覆盖M整数倍的随机序列，对于此题来说，最少能全覆盖的范围是1~49，即(rand7() - 1) * 7 + rand7()，调用此式子并舍去大于40的数，可以得到1~40的均匀分布
得到了1~40的均匀分布后，接着模10取余即可得到0~9的均匀分布，然后加1即是rand10

  */
    class Solution extends SolBase {
        public int rand10() {
            int r = (rand7() - 1) * 7 + rand7();
            while(r > 40)
                r = (rand7() - 1) * 7 + rand7();
            return r % 10 + 1;
        }
    }
}
