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