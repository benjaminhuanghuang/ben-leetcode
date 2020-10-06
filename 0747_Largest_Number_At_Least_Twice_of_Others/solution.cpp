/*
747. Largest Number At Least Twice of Others

https://leetcode.com/problems/largest-number-at-least-twice-of-others/
*/
#include <vector>

using namespace std;

class Solution_Naive
{
public:
  int dominantIndex(vector<int> &nums)
  {
    int maxNum = 0; //最大数
    int maxIndex;   //最大数的下标
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] >= maxNum)
      {
        maxNum = nums[i];
        maxIndex = i;
      }
    }
    for (int i = 0; i < nums.size(); i++)
    {
      if (i != maxIndex && nums[maxIndex] < 2 * nums[i])
      {
        return -1;
      }
    }
    return maxIndex;
  }
};

class Solution
{
public:
  int dominantIndex(vector<int> &nums)
  {
    int maxNum = -1;     //最大数
    int maxIndex;        //最大数的下标
    int secondMaxNum = -1; 
    for (int i = 0; i < nums.size(); i++)
    {
      if(nums[i] > maxNum)
      {
        int tmp = maxNum;
        maxNum= nums[i];
        secondMaxNum = tmp;
        maxIndex = i;
      }
      else if (nums[i] >= secondMaxNum)
      {
        secondMaxNum = nums[i];
      }
    }
    if (maxNum >=  2 * secondMaxNum)
    {
      return maxIndex;
    }
    return -1;
  }
};
