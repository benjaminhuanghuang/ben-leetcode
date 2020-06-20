/*
1317. Convert Integer to the Sum of Two No-Zero Integers

Level: Easy

https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers
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
  bool containzero(int n)
  {
    string str = to_string(n);
    for (int i = 0; i < str.size(); i++)
      if (str[i] == '0')
        return true;
    return false;
  }

  bool containZero2(int n)
  {
    while (n > 0)
    {
      if (n % 10 == 0)
        return true;
      n = n / 10;
    }
    return false;
  }
  vector<int> getNoZeroIntegers(int n)
  {
    for (int i = n - 1; i > 0; i--)
    {
      if (!containzero(i) && !containzero(n - i))
        return {i, n - i};
    }
    return {-1, -1};
  }
};