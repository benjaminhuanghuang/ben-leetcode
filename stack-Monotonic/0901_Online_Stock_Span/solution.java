package cn.huang.leetcode;
/*
901. Online Stock Span

Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price
for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going
backwards) for which the price of the stock was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would
be [1, 1, 1, 2, 1, 4, 6].



Example 1:

Input: ["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
Output: [null,1,1,1,2,1,4,6]
Explanation:
First, S = StockSpanner() is initialized.  Then:
S.next(100) is called and returns 1,
S.next(80) is called and returns 1,
S.next(60) is called and returns 1,
S.next(70) is called and returns 2,
S.next(60) is called and returns 1,
S.next(75) is called and returns 4,
S.next(85) is called and returns 6.

Note that (for example) S.next(75) returned 4, because the last 4 prices
(including today's price of 75) were less than or equal to today's price.

 */

import java.util.Stack;

/*
给定一个整数数组，为每一个数求出以它为结尾的满足这一条件的连续子数组的最大长度：其余的数都比它更小。

 */
public class LC_0901_OnlineStockSpan {
    /**
     * Approach 2: Monotonic Stack
     * 问题的实际上也可以转换成为：距离当前价格最近的价格大于当前价格的时间t。
     * 那么则有 span = curr - t + 1.
     * 因此这道题目可以转换成使用 单调栈 来解决。
     * <p>
     * 时间复杂度：O(n)
     * 每个元素进出栈各一次，因此总的时间复杂度为 O(2n) => 0(n)
     * 空间复杂度：O(n)
     * <p>
     * 类似的问题：
     * https://github.com/cherryljr/LintCode/blob/master/Largest%20Rectangle%20in%20Histogram.java
     * https://github.com/cherryljr/NowCoder/blob/master/%E6%9C%80%E5%B0%8F%E6%95%B0%E5%AD%97%E4%B9%98%E4%BB%A5%E5%8C%BA%E9%97%B4%E5%92%8C%E7%9A%84%E6%9C%80%E5%A4%A7%E5%80%BC.java
     */
    class StockSpanner {

        private Stack<int[]> stack;

        public StockSpanner() {
            stack = new Stack<>();
        }

        public int next(int price) {
            int span = 1;
            while (!stack.isEmpty() && price >= stack.peek()[0]) {
                span += stack.pop()[1];
            }
            stack.push(new int[]{price, span});
            return span;
        }
    }
}
