using System;

public class Solution309 {
    //http://www.cnblogs.com/grandyang/p/4997417.html
    public int MaxProfit(int[] prices) {
        int buy = int.MinValue, pre_buy = 0, sell = 0, pre_sell = 0;
        foreach(int price in prices) 
        {
            pre_buy = buy;
            buy = Math.Max(pre_sell - price, pre_buy);
            pre_sell = sell;
            sell = Math.Max(pre_buy + price, pre_sell);
        }
        return sell;
    }
}