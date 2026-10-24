/*

34. Find First and Last Position of Element in Sorted Array

https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    if (nums.size() < 1)
      return {-1, -1};

    int left = 0;
    int right = nums.size() - 1;
    vector<int> result(2, -1);
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      if (nums[mid] > target)
        right = mid - 1;
      else if (nums[mid] < target)
        left = mid + 1;
      else // mid == target, expand the range
      {
        result[0] = mid;
        result[1] = mid;
        int i = mid - 1;
        while (i >= 0 && nums[i] == target)
        {
          result[0] = i;
          i--;
        }
        i = mid + 1;
        while (i < nums.size() && nums[i] == target)
        {
          result[1] = i;
          i++;
        }
        break;  // DO NOT Forget
      }
    }
    return result;
  }
};