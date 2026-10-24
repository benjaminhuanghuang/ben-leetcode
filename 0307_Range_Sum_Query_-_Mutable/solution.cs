//http://www.cnblogs.com/grandyang/p/4985506.html
// http://blog.csdn.net/xyt8023y/article/details/49946789

/*
    树状数组Binary Indexed Tree，又称 Fenwick Tree

    Segment Tree 

    Time complexity:

        init O(nlogn)

        query: O(logn)

        update: O(logn)

*/
using System.Collections.Generic;

public class NumArrayMutalbe {
    private int[] num;
    private int[] bit;


    public NumArrayMutalbe(int[] nums) {
        this.num = new int[nums.Length + 1];
        this.bit = new int[nums.Length + 1];

        for (int i = 0; i < nums.Length; ++i) {
            Update(i, nums[i]);
        }
    }

    public void Update(int i, int val) {
        int diff = val - num[i + 1];
        for (int j = i +1; j< num.Length; j+=(j&-j))
        {
            bit[i] += diff;
        }
        num[i+1] = val;
    }

    public int SumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }

    int getSum(int i) {
        int res = 0;
        for (int j = i; j > 0; j -= (j&-j)) 
        {
            res += bit[j];
        }
        return res;
    }
}


// Your NumArray object will be instantiated and called as such:
// NumArray numArray = new NumArray(nums);
// numArray.SumRange(0, 1);
// numArray.Update(1, 10);
// numArray.SumRange(1, 2);