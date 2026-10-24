/*
354. Russian Doll Envelopes

You have a number of envelopes with widths and heights given as a pair of integers (w, h). 
One envelope can fit into another if and only if both the width and height of one envelope 
is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian 
doll is 3 ([2,3] => [5,4] => [6,7]).


*/
using System;
public class Solution354 {

    class Envelope {
        public int Width{get; set;}
        public int Height {get; set;}
        public int ContainCount { get; set; }

        public bool IsContainOther(Envelope other)
        {
            return Width > other.Width && Height > other.Height;
        }
    }

    public int MaxEnvelopes(int[,] envelopes) {
        int n = envelopes.GetLength(0);
		if (n <= 1) return n;
		Envelope[] e = new Envelope[n];
        for (int i = 0; i < n; i ++) {
            e[i] = new Envelope(){ Width = envelopes[i, 0], Height = envelopes[i, 1]};
        }

        Array.Sort(e, (x,y)=>{return (x.Height * x.Width).CompareTo(y.Height * y.Width);});

        int len =0;
        for(int i=1;i< n;i++)
        {
            for(int j=0;j< i;j++)
            {
                if(e[i].IsContainOther(e[j]))
                {
                    e[i].ContainCount = Math.Max(e[i].ContainCount, e[j].ContainCount + 1);
                    len = Math.Max(len, e[i].ContainCount);
                }
            }
        }
        return len;
    }
    /*
    上述方法是最基本的思路，但是还可以提高到O（NlogN）。提高的关键思想就是最长公共子序列（Longest Increasing Subsequence）。

    将长方形按照宽度排序（宽度一致就比较高，高度小的排序在后面），这样的话因为宽度是递增的，所以只需要考虑高度，这个时候就等同于LIS了。
    在宽度一致的情况下之所以要高度越小排序越后，是因为如果不这样做，在寻找高度的LIS的时候就会出现错误，
    [[5,4],[6,5],[6,7],[2,3]]这个例子很好的说明了问题，读者可以去实验一下。这一点很容易出错，读者需要学习其中的意义。
    上述常规思路问题就在于每次更新自己的ContainCount都要遍历前面的全部元素，优化的方法就是提供一个中间数组（长度与长方形的个数相同），
    该数组每个位置i存储了当前LIS长度的为i的最后一个元素。
    有了这个数组之后，我们就可以在遍历时数组中查询第一个小于当前高度的元素，如果都大于当前元素，那么该数组中的第一个元素为当前高度，
    如果都小于当前元素，那么i+1就是当前元素并且这个时候要更新当前的有效位数，如果找到了，那么替换该元素。从上面的步骤分析，
    该数组一定是有序的，所以查询可以用Binary Search，最后返回该数组的有效位数就可以了。这样整个算法的复杂度就是O（NlogN）

    */

    public int MaxEnvelopes_Bin(int[,] envelopes)
    {
        int n = envelopes.GetLength(0);
        if (n <= 1)
            return n;
        Envelope[] Envelopes = new Envelope[n];
        for (int i = 0; i < n; i++)
            Envelopes[i] = new Envelope(){Width = envelopes[i, 0], Height= envelopes[i, 1]};
        //按照宽度排序（宽度一致就比较高，高度小的排序在后面）
        Array.Sort(Envelopes, (x,y)=> {int result = x.Width.CompareTo(y.Width); 
                                        return result==0 ? y.Height.CompareTo(x.Height): result;});
        int[] dp = new int[n];
        int dpindex = 0;
        for (int i = 0; i < n; i++)
        {
            int currentIndex = Array.BinarySearch(dp, 0, dpindex, Envelopes[i].Height);
            if (currentIndex < 0)
                currentIndex = ~currentIndex;
            dp[currentIndex] = Envelopes[i].Height;
            if (currentIndex == dpindex)
                dpindex++;
        }
        return dpindex;
    }
}

/*
int[,] input = new int[,] { { 5, 4 }, { 6, 4 }, { 6, 7 }, { 2, 3 } };
*/