/*
179. Largest Number  [M]

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/
using System;
using System.Linq;

public class Solution179 {
    //  compare i + j with j + i; change it to string and using Array sort to compare it.
    public string LargestNumber(int[] nums) {
        Array.Sort(nums, (i, j) => String.Compare(j.ToString() + i.ToString(), i.ToString() + j.ToString(), StringComparison.Ordinal));

        var res = nums.Aggregate(string.Empty, (s, i) => s + i);

        if (res.Any() && res[0].Equals('0'))
        {
            return "0";
        }

        return res;
    }
}