/*
747. Largest Number At Least Twice of Others

https://leetcode.com/problems/largest-number-at-least-twice-of-others/
*/
#include <vector>

using namespace std;

class Solution
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
    int lastMaxNum = -1; //上一个最大数
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] >= lastMaxNum)
      {
        //先看一看当前的是否大于上一个最大值
        lastMaxNum = nums[i];
        //先让上一个最大值等于当前的
        if (nums[i] > maxNum)
        { //如果这个比最大值还大的话，更换当前最大值和上一个最大值
          lastMaxNum = maxNum;
          maxNum = nums[i];
          maxIndex = i;
        }
      }
    }
    if (maxNum < 2 * lastMaxNum)
    {
      return -1;
    }
    return maxIndex;
  }
};
