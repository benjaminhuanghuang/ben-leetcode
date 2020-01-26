/*
386. Lexicographical Numbers

Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
*/
using System.Collections.Generic;

public class Solution386 {
    //http://www.cnblogs.com/grandyang/p/5798275.html
    //按个位数遍历，在遍历下一个个位数之前，先遍历十位数，十位数的高位为之前的个位数，只要这个多位数并没有超过n，
    //就可以一直往后遍历，如果超过了，我们除以10，然后再加1，如果加1后末尾形成了很多0，那么我们要用个while循环把0都去掉，然后继续运算
    public IList<int> LexicalOrder(int n) {
        List<int> res = new List<int>();
        int cur = 1;
        for (int i = 0; i < n; ++i) 
        {
            res.Add(cur);
            if (cur * 10 <= n) {
                cur *= 10;
            } 
            else 
            {
                if (cur >= n) 
                    cur /= 10;
                cur += 1;
                while (cur % 10 == 0) 
                    cur /= 10;
            }
        }
        return res;
    }
}