/*
581. Shortest Unsorted Continuous Subarray

https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
*/

#include <vector>

using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> sortedNums(nums);
        sort(begin(sortedNums), end(sortedNums));
        int start = nums.size();//注意起始位置！！
        int end = 0;
     
        for (int i = 0; i < sortedNums.size(); ++i)
        {
            if (nums[i] != sortedNums[i])
            {
                start = min(start, i);
                end = max(end, i);
            }
        }
         return (end - start >= 0 ? end - start + 1 : 0);
    }
};