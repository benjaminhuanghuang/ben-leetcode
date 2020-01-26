/*
321. Create Maximum Number

Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum 
number of length k <= m + n from digits of the two. The relative order of the digits from the 
same array must be preserved. Return an array of the k digits. You should try to optimize your 
time and space complexity.

Example 1:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]

Example 2:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]

Example 3:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
return [9, 8, 9]
*/
/*
    1. 从数组nums中挑选出t个数，在保持元素相对顺序不变的情况下，使得选出的子数组最大化。
    2. 在保持元素相对顺序不变的前提下，将数组nums1与数组nums2合并，使合并后的数组最大化。
    int len1 = nums1.Length;
    int len2 = nums2.Length;
    List<int>res = new List<int>();

    for (int i = Math.Max(0, k-len2) ; i< Math.Min(k, len1) + 1)
    {
        int tmp = Merge(GetMax(nums1, i), getMax(nums2, k - i));
        res = Max(tmp, res);
    }
*/
using System;
using System.Collections.Generic;

public class Solution321 {
    //http://buttercola.blogspot.com/2016/06/leetcode-321-create-maximum-number.html
    public int[] MaxNumber(int[] nums1, int[] nums2, int k) {
        int len1 = nums1.Length;
        int len2 = nums2.Length;
        int[] res = new int[k];

        for (int i = Math.Max(0, k-len2) ; i< Math.Min(k, len1) + 1; i++)
        {
            int[] tmp = Merge(GetMax(nums1, i), GetMax(nums2, k - i));
            res = isGreaterArray(res, tmp) ? res : tmp;
        }
        return res;
    }
    // 不改变元素顺序，获得最大子数组
    public int[] GetMax2(int[] nums, int k) 
    {
        int drop = nums.Length - k;
        List<int> res = new List<int>();
        foreach (int num in nums) 
        {
            while (drop > 0 && res.Count > 0 && res[res.Count-1] < num) {
                res.RemoveAt(res.Count-1);
                --drop;
            }
            res.Add(num);
        } 
        return res.ToArray();
    }

    public int[] GetMax(int[] nums, int k) {
        int[] res = new int[k];
        int len = 0;
        for (int i = 0; i < nums.Length; i++) {
            while (len > 0 && len + nums.Length - i > k && res[len - 1] < nums[i]) {
                len--;
            }
            if (len < k)
                res[len++] = nums[i];
        }
        return res;
    }

    //此方法错误，当nums1= 6，7  nums 6，0，4时，此方法merge结果为66704
    // 而正确答案为  67604
    private int[] Merge_error(int[] nums1, int[] nums2) 
    {
        int len1 = nums1.Length;
        int len2 = nums2.Length;
        if (len1 <=0)
            return nums2;
        if (len2 <= 0)
            return nums1;
        int[] res = new int[len1 + len2];
        int i1 =0, i2=0;
        for(int l = 0; l < len1 + len2; ++l) 
        {
            int n1 = i1 < len1? nums1[i1]:int.MinValue;
            int n2 = i2 < len2? nums2[i2]:int.MinValue;
            if(n1 > n2 && i1< len1)
            {
                res[l] = n1;
                i1++;
            }
            else
            {
                res[l] = n2;
                i2++;
            }
        }
        return res;
    }

    private int[] Merge(int[] nums1, int[] nums2) 
    {
        int len1 = nums1.Length;
        int len2 = nums2.Length;
        if (len1 <=0)
            return nums2;
        if (len2 <= 0)
            return nums1;
        int[] res = new int[len1 + len2];
        int i1 =0, i2=0;
        for(int l = 0; l < len1 + len2; ++l) 
        {
            if (greater(nums1, i1, nums2, i2)) {
                res[l] = nums1[i1++];
            } else {
                res[l] = nums2[i2++];
            }
        }
        return res;
    }

    private bool isGreaterArray(int[] nums1, int[] nums2)
    {
        int len1 = nums1.Length;
        int len2 = nums2.Length;
        int i=0,j=0;
        for(; i < nums1.Length && j < nums2.Length; ++i, ++j) 
        {
            if (nums1[i] > nums2[j])
                return true;
            if (nums1[i] < nums2[j])
                return false;
        }
        return i != nums1.Length;
    }
    // Note  [6,7]  > [6,0,4] !!!!
    private bool greater(int[] list1, int pos1, int[] list2, int pos2) {
        int n1 = list1.Length;
        int n2 = list2.Length;
         
        while (pos1 < n1 && pos2 < n2 && list1[pos1] == list2[pos2]) {
            pos1++;
            pos2++;
        }
         
        if (pos2 == n2) {
            return true;
        }
         
        if (pos1 < n1 && list1[pos1] > list2[pos2]) {
            return true;
        }
         
        return false;
    }
}

/*
        var nums1 = new int[]{3,4,6,5};
        var nums2 = new int[]{9,1,2,5,8,3};


        var s = new Solution321();
        var result = s.MaxNumber(nums1, nums2, 5);  
 
        Console.WriteLine(result);
*/