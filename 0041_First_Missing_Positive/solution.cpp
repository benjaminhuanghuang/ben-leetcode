/*
41. First Missing Positive [Hard]

https://leetcode.com/problems/first-missing-positive/
*/
#include <vector>

using namespace std;
/*
https://www.youtube.com/watch?v=jfb72FfxWKU
桶排序
 */
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 1;
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] > 0 && nums[i] < nums.size() && nums[nums[i] - 1] != nums[i])
            {
                // Put num[i] to the right position num[nuims[i]-1] (nums[i] != i + 1)
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return nums.size() + 1;
    }
};