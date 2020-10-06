/*
665. Non-decreasing Array

https://leetcode.com/problems/non-decreasing-array/
*/
#include <vector>

using namespace std;

/*

    [3,4,2,3]
    nums[i] < nums[i - 1]，需要对二者进行修改，要么修改array[i]，要么修改array[i+1]，如：[3,5,2,4]，
    具体是对nums[i-1]做修改还是对nums[i]做修改，需要判断nums[i-1]和nums[i+1]两者的大小，具体分两种情况
    情况一：[2,5,3,4]，当i=1时，nums[i]=5，此时nums[i-1]=2 < nums[i+1]=3，则需修改“5”为“3”，即令nums[i]=nums[i+1]，则保证数组返回真；
    情况二：[4,5,3,7]，当i=1时，anums[i]=5，此时nums[i-1]=4 > nums[i+1]=3，则需修改“3”为“5”，即令nums[i+1]=nums[i]，则保证数组返回真；
*/

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        bool found = false;
        for (int i = 1; i < nums.size(); i++)
        {
            // decending
            if (nums[i] < nums[i - 1])
            {
                if (found)
                {
                    return false;
                }
                else
                {   
                    // nums[i] < nums[i - 1] and nums[i] < nums[i - 2]
                    // like [3,4,2,3]
                    if (i - 2 >= 0 && nums[i] < nums[i - 2])
                        nums[i] = nums[i - 1];
                    found = true;
                }
            }
        }
        return true;
    }
};