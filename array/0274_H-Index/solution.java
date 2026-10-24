package cn.huang.leetcode;
/*
274. H-Index

Given an array of citations (each citation is a non-negative integer) of a researcher, write a function
to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have
at least h citations each, and the other N − h papers have no more than h citations each."

Example:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had
             received 3, 0, 6, 1, 5 citations respectively.
             Since the researcher has 3 papers with at least 3 citations each and the remaining
             two with no more than 3 citations each, her h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

 */

import java.util.Arrays;

/*
给定一个数组代表论文被引用次数。要求计算h-index。

h-index定义如下： 一个学者发表的n篇论文中，他有h篇被引用至少h次，而其他的n-h篇被引用次数都不超过h。

https://segmentfault.com/a/1190000003794831
 */
public class LC_0274_HIndex {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);
        int h = 0;
        for(int i = 0; i < citations.length; i++){
            // 得到当前的H指数
            // 引用数citations[i]，大于该引用数文献的数量是citations.length - i
            int currH = Math.min(citations[i], citations.length - i);
            if(currH > h){
                h = currH;
            }
        }
        return h;
    }
}
