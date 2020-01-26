/*
164. Maximum Gap

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

*/
using System;
using System.Linq;
using System.Collections.Generic;

public class Solution164
{
    //http://magicsong.xyz/leetcode/leetcode%E4%B9%8Bmaximum-gap%E8%A7%A3%E9%A2%98%E6%80%9D%E8%B7%AF%EF%BC%88c%EF%BC%89/
    // if we can sort it, it will be really easy. but it takes O(nlgn). 
    // Solve it in linear time. we can think about linear time sort, bucket sort algorithm.
    // put all int into 32 buckets according to its length. then sort each bucket to get the 
    // maximum gap.
    public int MaximumGap(int[] nums)
    {
        if (nums == null || nums.Length < 2)
            return 0;

        var length = nums.Length;
        var minVal = nums.Min();
        var maxVal = nums.Max();

        var bucketSize = Math.Max(1, (maxVal - minVal - 1) / (length - 1) + 1);
        var bucketNumber = (maxVal - minVal) / bucketSize + 1;
        var buckets = new Tuple<int, int>[bucketNumber];
        
        int bucketIndex = 0;
        foreach (var i in nums)
        {
            bucketIndex = (i - minVal) / bucketSize;
            Tuple<int,int> bucket = buckets[bucketIndex];
            if (bucket == null)
                buckets[bucketIndex] = new Tuple<int, int>(i, i);  // min an max value in bucket
            else
                buckets[bucketIndex] = new Tuple<int, int>(Math.Min(bucket.Item1, i), Math.Max(bucket.Item2, i));  // min an max value in bucket
        }
        var ans = 0;
        bucketIndex = 0;
        while (bucketIndex < bucketNumber)
        {
            if (buckets[bucketIndex] == null)
            {
                bucketIndex += 1;
                continue;
            }
            int nextBucket = bucketIndex + 1;
            while (nextBucket < bucketNumber && buckets[nextBucket] == null)
                nextBucket += 1;
            if (nextBucket < bucketNumber)
                ans = Math.Max(ans, buckets[nextBucket].Item1- buckets[bucketIndex].Item2);
            bucketIndex = nextBucket;
        }
        return ans;
    }
}


/*

var s = new Solution164();
var res = s.MaximumGap(new int[]{1, 10000000});

*/

