/*
453. Minimum Moves to Equal Array Elements

Given a non-empty integer array of size n, find the minimum number of moves required to make all array 
elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/
using System.Linq;

public class Solution453 {
    //一次移动将n - 1个元素加1，等价于将剩下的1个元素减1。
    // [1,2147483647] nums.Sum() cause overflow, this solution is ok by python
    public int MinMoves(int[] nums) {
        // return nums.Sum() - nums.Min() * nums.Length;

        int min = int.MaxValue;
        long sum = 0;
        foreach (int i in nums)
        {
            if (i < min)
                min = i;
            sum += i;
        }
        return (int)(sum - min * nums.Length);
    }
}