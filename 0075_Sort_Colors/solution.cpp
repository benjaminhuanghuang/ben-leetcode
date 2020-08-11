/*
75. Sort Colors

https://leetcode.com/problems/sort-colors/

*/
#include <vector>

using namespace std;

class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    if (nums.empty())
    {
      return;
    }
    int lastRed = 0, firstBlue = nums.size() - 1;
    int i = 0;
    while (i <= firstBlue)
    {
      if (nums[i] == 0 && i != lastRed)
      {
        swap(nums, lastRed++, i);
      }
      else if (nums[i] == 2 && i != firstBlue)
      {
        swap(nums, i, firstBlue--);
      }
      else
        ++i;
    }
  }

  void swap(vector<int> &nums, int i, int j)
  {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
};