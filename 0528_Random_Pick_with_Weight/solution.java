package cn.huang.leetcode;

import java.util.Random;

/*
528. Random Pick with Weight

Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which
randomly picks an index in proportion to its weight.

Note:

    1 <= w.length <= 10000
    1 <= w[i] <= 10^5
    pickIndex will be called at most 10000 times.

Example 1:

Input:
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]

Example 2:

Input:
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]

Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument,
the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.

 */

/*
这道题给了一个权重数组，要求按照权重挑选索引
比如[1,99]中，有1%的概率挑选到索引0，有99%的概率挑选到索引1.

现在的点就不是随机等概率的选取了，而是要根据权重的不同来区别选取。
比如题目中例子2，权重为 [1, 3]，表示有两个点，权重分别为1和3，那么就是说一个点的出现概率是四分之一，另一个出现的概率是四分之三。
由于我们的rand()函数是等概率的随机，那么我们如何才能有权重的随机呢，我们可以使用一个trick，由于权重是1和3，相加为4，
那么我们现在假设有4个点，然后随机等概率取一个点，随机到第一个点后就表示原来的第一个点，随机到后三个点就表示原来的第二个点，
这样就可以保证有权重的随机啦。那么我们就可以建立权重数组的累加和数组，比如若权重数组为 [1, 3, 2] 的话，那么累加和数组为 [1, 4, 6]，
整个的权重和为6，我们 rand() % 6，可以随机出范围 [0, 5] 内的数，随机到 0 则为第一个点，随机到 1，2，3 则为第二个点，
随机到 4，5 则为第三个点，所以我们随机出一个数字x后，然后再累加和数组中查找第一个大于随机数x的数字，
使用二分查找法可以找到第一个大于随机数x的数字的坐标，即为所求，
 */
public class LC_0528_RandomPickwithWeight {
    class Solution {
        int[] sums;
        int max;
        Random random;

        public Solution(int[] w) {
            sums = new int[w.length];
            sums[0] = w[0];
            for (int i = 1; i < sums.length; i++) {
                sums[i] = sums[i - 1] + w[i];
            }
            max = sums[sums.length - 1];
            random = new Random();
        }

        public int pickIndex() {
            int rand = random.nextInt(max) + 1;
            int index = findIndex(sums, rand);
            return index;
        }

        private int findIndex(int[] nums, int k) {
            int start = 0, end = nums.length - 1;
            while (start + 1 < end) {
                int mid = start + (end - start) / 2;
                if (nums[mid] == k)
                    return mid;
                else if (nums[mid] < k)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            if (k > nums[end])
                return end + 1;
            else if (k > nums[start])
                return start + 1;
            else
                return start;
        }
    }

}
