/*
728. Self Dividing Numbers

Level: Easy

https://leetcode.com/problems/self-dividing-numbers
*/
#include <vector>
#include <string>
#include <unordered_map>
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
private:
  bool isSelfDividing(int num)
  {
    int tmp = num;

    while (tmp > 0)
    {
      int digit = tmp % 10;
      if (digit == 0)
      {
        return false;
      }

      if (num % digit != 0)
      {
        return false;
      }
      tmp = tmp / 10;
    }
    return true;
  }

public:
  vector<int> selfDividingNumbers(int left, int right)
  {
    vector<int> ans;
    for (int i = left; i <= right; i++)
    {
      if (isSelfDividing(i))
      {
        ans.push_back(i);
      }
    }
    return ans;
  }

  vector<int> selfDividingNumbers_v2(int left, int right)
  {
    vector<int> ans;
    for (int i = left; i <= right; i++)
    {
      int n = i, m = i;
      int c1 = 0, c2 = 0;
      while (n > 0)
      {
        int dig = n % 10;
        c1++;
        if (dig == 0)
          break;

        if (m % dig == 0)
          c2++;
        n = n / 10;
      }
      if (c1 == c2)
        ans.push_back(m);
    }
    return ans;
  }
};