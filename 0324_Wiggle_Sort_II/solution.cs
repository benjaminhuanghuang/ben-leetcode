/*
324. Wiggle Sort II
#280

Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

https://www.hrwhisper.me/leetcode-wiggle-sort-ii/
https://discuss.leetcode.com/topic/32929/o-n-o-1-after-median-virtual-indexing

http://www.cnblogs.com/grandyang/p/5139057.html
相当于把有序数组从中间分成两部分，然后从前半段的末尾取一个，在从后半的末尾去一个，这样保证了第一个数小于第二个数，
然后从前半段取倒数第二个，从后半段取倒数第二个，这保证了第二个数大于第三个数，且第三个数小于第四个数，
以此类推直至都取完
*/
using System;

public class Solution324 {
    /*
    http://www.cnblogs.com/grandyang/p/5139057.html
    相当于把有序数组从中间分成两部分，然后从前半段的末尾取一个，在从后半的末尾去一个，这样保证了第一个数小于第二个数，
    然后从前半段取倒数第二个，从后半段取倒数第二个，这保证了第二个数大于第三个数，且第三个数小于第四个数，
    以此类推直至都取完
    */
    public void WiggleSort(int[] nums) {
        Array.Sort(nums);
        int[] temp = new int[nums.Length];
        int s = (nums.Length + 1) >> 1;
        int t = nums.Length;

        for (int i = 0; i < nums.Length; i++) {
            temp[i] = (i & 1) == 0 ?  nums[--s] : nums[--t] ;
        }
 
        for (int i = 0; i < nums.Length; i++)
            nums[i] = temp[i];
    }

    public void WiggleSort2(int[] nums) {
        Array.Sort(nums);
        
        for(int i = 2; i < nums.Length; i+=2){
            int tmp = nums[i-1];
            nums[i-1] = nums[i];
            nums[i] = tmp;
        }
    }
    /* 
    public void WiggleSort3(int[] nums) {
         int n = nums.Length;
         for (int i = 1; i < n; i++)
             if (((i & 1) && nums[i] < nums[i - 1]) || (!(i & 1) && nums[i] > nums[i - 1]))
             {
                int tmp = nums[i-1];
                nums[i-1] = nums[i];
                nums[i] = tmp;
             }
    }
    */
}


/*
var nums = new int[] {3, 5, 2, 1, 6, 4};
var s = new Solution324();
s.WiggleSort2(nums);
foreach (var i in nums)
{
    Console.WriteLine(i);
}
*/