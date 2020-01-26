/*
473. Matchsticks to Square

Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match 
girl has, please find out a way you can make one square by using up all those matchsticks. You 
should not break any stick, but you can link them up, and each matchstick must be used exactly one 
time.

Your input will be several matchsticks the girl has, represented with their stick length. Your 
output will either be true or false, to represent whether you could make one square using all the 
matchsticks the little match girl has.

Example 1:
Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came two sticks with 
length 1.
Example 2:
Input: [3,3,3,3,4]
Output: false

Explanation: You cannot find a way to form a square with all the matchsticks.
Note:
The length sum of the given matchsticks is in the range of 0 to 10^9.
The length of the given matchstick array will not exceed 15.
 */

using System;
using System.Collections.Generic;
using System.Linq;

/*
-- sum the array and divide by 4, calculate the length of edge.
-- using dfs solution, to divide each number into 4 group, to check true or false.
-- when divide, check whether each group sum larger than edge.
 */
public class Solution473
{
    public bool Makesquare(int[] nums)
    {
        int sum = nums.Sum();

        if (sum % 4 != 0 || sum == 0)
            return false;
        Array.Sort(nums);
        Array.Reverse(nums);  //important !!! TLE without it
        return dfs(nums, new int[4], 0, sum / 4);
    }
    private bool dfs(int[] nums, int[] sums, int index, int target)
    {
        if (index == nums.Length)
        {
            return (sums[0] == target && sums[1] == target && sums[2] == target);
        }
        for (int i = 0; i < 4; i++)
        {
            if (sums[i] + nums[index] > target) continue;
            sums[i] += nums[index];
            if (dfs(nums, sums, index + 1, target)) return true;
            sums[i] -= nums[index];
        }
        return false;
    }

}

/*
var input = new int[]{8,16,24,32,40,48,56,64,72,80,88,96,104,112,60};
var s = new Solution();
s.Makesquare(input);
 */
