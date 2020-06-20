/*
1295. Find Numbers with Even Number of Digits

Level: Easy

https://leetcode.com/problems/find-numbers-with-even-number-of-digits
*/
#include <vector>
#include <string>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  int findNumbers_v2(vector<int> &nums)
  {

    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      int n = nums[i];
      int count = 0;
      while (n)
      {
        n /= 10;
        count++;
      }
      if (!(count & 1))
        res++;
    }

    return res;
  }

  int findNumbers(vector<int> &nums)
  {
    int count = 0;
    for (int i : nums)
    {
      if ((getDigits(i) & 1) == 0)
      {
        count++;
      }
    }
    return count;
  }

private:
  int getDigits(int num)
  {
    int digits = 0;
    while (num > 0)
    {
      num = num / 10;
      digits++;
    }
    return digits;
  }
};