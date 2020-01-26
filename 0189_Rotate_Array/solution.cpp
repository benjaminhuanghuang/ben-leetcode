/*
189. Rotate Array
Given an array, rotate the array to the right by k steps, where k is non-negative.

https://leetcode.com/problems/rotate-array/
*/
#include <vector>

using namespace std;

class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    if (nums.empty())
      return;
    k %= nums.size();
    if (k == 0)
      return;
    reverse(begin(nums), end(nums));
    reverse(nums.begin(), nums.begin() + k);
    reverse(begin(nums) + k, end(nums));
  }
};