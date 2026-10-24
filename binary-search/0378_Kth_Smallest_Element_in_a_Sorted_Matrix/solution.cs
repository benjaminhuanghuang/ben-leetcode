/*
378. Kth Smallest Element in a Sorted Matrix  


Given a n x n matrix where each of the rows and columns are sorted in ascending order, 
find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.
*/
using System.Collections.Generic;

public class Solution378
{
    // you are already iterating the full matrix, by this time we can tell the kth smallest, 
    // but the input is sorted so that we will avoid full traversal, on top of it you are 
    // sorting which is o(n log n). No interviewer accepts this answer.
    public int KthSmallest_Lazy(int[,] matrix, int k)
    {
        int h = matrix.GetLength(0);
        List<int> list = new List<int>();
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < h; j++)
                list.Add(matrix[i, j]);
        }
        list.Sort();
        return list[k - 1];
    }

    /*
        这道题的难点在于数组并不是蛇形有序的，意思是当前行的最后一个元素并不一定会小于下一行的首元素，
        所以并不能直接定位第K小的元素，

        由于是有序矩阵，那么左上角的数字一定是最小的，而右下角的数字一定是最大的，所以这个是我们搜索的范围，
        然后我们算出中间数字mid，由于矩阵中不同行之间的元素并不是严格有序的，所以我们要在每一行都查找一下mid，
        我们使用upper_bound，这个函数是查找第一个大于目标数的元素，如果目标数在比该行的尾元素大，
        则upper_bound返回该行元素的个数，如果目标数比该行首元素小，则upper_bound返回0, 
        我们遍历完所有的行可以找出中间数是第几小的数，然后k比较，进行二分查找
        O(nlgn*lgX) 其中X为最大值和最小值的差值
     */
    public int KthSmallest(int[,] matrix, int k)
    {
        int n = matrix.GetLength(0);
        int low = matrix[0, 0];
        int high = matrix[n - 1, n - 1];

        while (low < high)
        {
            // 注意优先级
            int mid = low + ((high - low) >> 1);
            int count = this.count(matrix, mid);
            if (count < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    private int count(int[,] matrix, int target)
    {
        int m = matrix.GetLength(0);
        int i = m - 1;
        int j = 0;
        int count = 0;

        while (i >= 0 && j < m)
        {
            if (matrix[i, j] <= target)
            {
                count += i + 1;
                j++;
            }
            else
            {
                i--;
            }
        }

        return count;
    }
}