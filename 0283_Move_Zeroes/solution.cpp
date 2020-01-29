/*
283. Move Zeroes

Level: Easy

https://leetcode.com/problems/move-zeroes
*/

#include <vector>

using namespace std;

class Solution
{
public:
  void moveZeroes(vector<int> &nums)
  {
    int last = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] != 0)
      {
        nums[last] = nums[i];
        last++;
      }
    }
    while (last < nums.size())
    {
      nums[last++] = 0;
    }
  }
};