/*
507. Perfect Number

Level: Easy

https://leetcode.com/problems/perfect-number
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
public:
  bool checkPerfectNumber(int num)
  {
    //其他因子的范围是[2, sqrt(n)]
    if (num == 1)
      return false;
    int sum = 1;

    for (int i = 2; i * i <= num; ++i)
    {
      if (num % i == 0)
        sum += (i + num / i);
      if (i * i == num)
        sum -= i;
      if (sum > num)
        return false;
    }
    return sum == num;
  }
};