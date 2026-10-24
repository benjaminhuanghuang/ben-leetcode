/*
238. Product of Array Except Self

Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to 
the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra 
space for the purpose of space complexity analysis.)
*/

public class Solution238 {
    // with more than 2 0s, simply return all 0s; 
    // with only 1 0s, find that 0 element and do the product; 
    // without 0s, divide the product by current element.
    public int[] SelfExcludingProduct_1(int[] input)
    {
        var res = new int[input.Length];

        var numberOf0 = 0;
        var products = 1;
        foreach (var i in input)
        {
            if (i == 0)
            {
                numberOf0++;
            }
            else
            {
                products *= i;
            }
        }

        if (numberOf0 > 1)
        {
            return res;
        }
        else if (numberOf0 == 1)
        {
            for (int i = 0; i < input.Length; i++)
            {
                if (input[i] == 0)
                {
                    res[i] = products;
                }
            }
        }
        else
        {
            for (int i = 0; i < input.Length; i++)
            {
                res[i] = products / input[i];
            }
        }

        return res;
    }

    public int[] ProductExceptSelf(int[] nums) {
        var res = new int[nums.Length];

        for (int i = nums.Length - 1; i >= 0; i--)
        {
            if (i == nums.Length - 1) 
                res[i] = nums[i];
            else 
                res[i] = res[i + 1] * nums[i];
        }

        for (int i = 1; i < nums.Length; i++)
        {
            nums[i] = nums[i - 1] * nums[i];
        }

        for (int i = 0; i < nums.Length; i++)
        {
            res[i] = (i == nums.Length - 1 ? 1: res[i + 1]) * (i ==0 ? 1: nums[i - 1]);
        }

        return res;
    }
}